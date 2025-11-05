#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head->next == nullptr && n==1){
            delete(head);
            return nullptr;
        }

        ListNode *temp1 = head;
        ListNode *temp2 = head;

        int count =0;

        while(temp2!=nullptr){
            if(count<n+1){
                temp2=temp2->next;
                count++;
            }
            else{
                temp1=temp1->next;
                temp2=temp2->next;
            }
                     
        }

        if(temp2==nullptr && count!=n+1){
            //  cout << "Error";
             ListNode *dummy = head;
             head = head->next;
             delete (dummy);
             return head;
         }
        else{
            ListNode *dummy = temp1->next;
            temp1->next = temp1->next->next;
            delete(dummy);
         }

        return head;
    }
};

// Utility function to print a linked list
void printList(ListNode* head) {
    while(head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Utility to create a linked list from vector
ListNode* createList(const vector<int>& vals) {
    if(vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for(size_t i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    vector<int> vals = {1, 2};
    ListNode* head = createList(vals);

    cout << "Original list: ";
    printList(head);

    Solution sol;
    int n = 2; // Remove 2nd node from end
    head = sol.removeNthFromEnd(head, n);

    cout << "Modified list: ";
    printList(head);

    return 0;
}

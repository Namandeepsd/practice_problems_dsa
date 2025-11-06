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
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        stack<int> st;
        while (temp != nullptr) {
            st.push(temp->val);
            temp = temp->next;
        }   
        temp = head;
        while (temp != nullptr) {
            if (temp->val != st.top()) {
                return false;
            }
            temp = temp->next;
            st.pop();
        }
        return true;
    }
};

// Utility: create a linked list from vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (size_t i = 1; i < vals.size(); i++) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

// Utility: free all nodes
void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}

int main() {
    vector<int> vals = {1, 2, 3, 2, 1,5};
    ListNode* head = createList(vals);

    Solution sol;
    bool result = sol.isPalindrome(head);

    cout << "List: ";
    for (int v : vals) cout << v << " ";
    cout << endl;

    cout << "Is Palindrome? " << (result ? "Yes" : "No") << endl;

    deleteList(head);
    return 0;
}

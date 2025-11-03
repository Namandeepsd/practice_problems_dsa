#include <iostream>
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
    ListNode* oddEvenList(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return head; 

        ListNode* temp = head;

        ListNode *oddLL = new ListNode(temp->val);
        ListNode *tempOdd = oddLL;
        ListNode *headOdd = oddLL;

        ListNode *evenLL = new ListNode(temp->next->val);
        ListNode *tempEven = evenLL;
        ListNode *headEven = evenLL;

        if (temp->next->next != nullptr)
            temp = temp->next->next;
        else
            temp = nullptr;

        int count = 3;
        while (temp != nullptr) {
            ListNode *dummy = new ListNode(temp->val);
            if (count % 2 != 0) {
                tempOdd->next = dummy;
                tempOdd = tempOdd->next;
            } else {
                tempEven->next = dummy;
                tempEven = tempEven->next;
            }
            count += 1;
            temp = temp->next;
        }

        tempOdd->next = headEven;

        return headOdd;
    }
};

// Utility function to print a linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        cout << temp->val;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

// Utility function to create a linked list from array
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for (int i = 1; i < n; i++) {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    ListNode* head = createList(arr, n);

    cout << "Original list: ";
    printList(head);

    Solution s;
    ListNode* result = s.oddEvenList(head);

    cout << "Odd-Even arranged list: ";
    printList(result);

    return 0;
}

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        int sum = 0;
        int carry = 0;

        sum = temp1->val + temp2->val + carry;

        ListNode *l3 = new ListNode(sum % 10);
        ListNode *head = l3;

        carry = sum / 10;

        temp1 = temp1->next;
        temp2 = temp2->next;

        while (temp1 != nullptr || temp2 != nullptr) {
            ListNode *dummy;
            if (temp1 == nullptr) {
                sum = temp2->val + carry;
                dummy = new ListNode(sum % 10);
                carry = sum / 10;
                l3->next = dummy;
                l3 = l3->next;
            }
            else if (temp2 == nullptr) {
                sum = temp1->val + carry;
                dummy = new ListNode(sum % 10);
                carry = sum / 10;
                l3->next = dummy;
                l3 = l3->next;
            }
            else {
                sum = temp1->val + temp2->val + carry;
                dummy = new ListNode(sum % 10);
                carry = sum / 10;
                l3->next = dummy;
                l3 = l3->next;
            }
            if (temp1 != nullptr) temp1 = temp1->next;
            if (temp2 != nullptr) temp2 = temp2->next;
        }

        if (carry != 0) {
            ListNode *dummy = new ListNode(carry);
            l3->next = dummy;
        }
        return head;
    }
};

// Helper to create a linked list from an array
ListNode* createList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Helper to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};

    ListNode* l1 = createList(arr1, 3);
    ListNode* l2 = createList(arr2, 3);

    Solution sol;
    ListNode* result = sol.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);

    return 0;
}

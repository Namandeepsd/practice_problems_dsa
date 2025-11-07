#include <bits/stdc++.h>
using namespace std;

/*****************************************************************
 * Definition for singly-linked list node
 *****************************************************************/
template <typename T>
class LinkedListNode {
public:
    T data;
    LinkedListNode<T>* next;

    LinkedListNode(T data) {
        this->data = data;
        next = nullptr;
    }
};

/*****************************************************************
 * Function to reverse a linked list
 *****************************************************************/
LinkedListNode<int>* reverse(LinkedListNode<int>* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    LinkedListNode<int>* newHead = reverse(head->next);
    LinkedListNode<int>* front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}

/*****************************************************************
 * Function to add one to the number represented by linked list
 *****************************************************************/
LinkedListNode<int>* addOneToList(LinkedListNode<int>* head) {
    if (head == nullptr) return new LinkedListNode<int>(1);

   

    head = reverse(head);
    LinkedListNode<int>* temp = head;
    int sum = temp->data + 1;
    int carry = sum / 10;
     temp->data = sum % 10;

    if(temp->next == nullptr && carry!=0) {
        temp->next = new LinkedListNode<int>(carry);
        return reverse(head);
    }
    
    temp->data = sum % 10;
    temp = temp->next;

    while (carry != 0 && temp != nullptr) {
        sum = temp->data + carry;
        temp->data = sum % 10;
        carry = sum / 10;

        if (temp->next == nullptr && carry > 0) {
            temp->next = new LinkedListNode<int>(carry);
            carry = 0;
        }

        temp = temp->next;
    }

    head = reverse(head);
    return head;
}

/*****************************************************************
 * Helper functions for testing
 *****************************************************************/
LinkedListNode<int>* createList(const vector<int>& arr) {
    if (arr.empty()) return nullptr;
    LinkedListNode<int>* head = new LinkedListNode<int>(arr[0]);
    LinkedListNode<int>* current = head;
    for (int i = 1; i < arr.size(); ++i) {
        current->next = new LinkedListNode<int>(arr[i]);
        current = current->next;
    }
    return head;
}

void printList(LinkedListNode<int>* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

/*****************************************************************
 * Main function for local testing
 *****************************************************************/
int main() {
    // Example test cases
    vector<vector<int>> testCases = {
        {9, 9, 9},
        {9},
        {9, 5, 6, 5, 4, 3, 5}
    };

    for (auto& test : testCases) {
        LinkedListNode<int>* head = createList(test);
        cout << "Original List: ";
        printList(head);

        LinkedListNode<int>* newHead = addOneToList(head);
        cout << "After Adding 1: ";
        printList(newHead);
        cout << "-----------------------------" << endl;
    }

    return 0;
}

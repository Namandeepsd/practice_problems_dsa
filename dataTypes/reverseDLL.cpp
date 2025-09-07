#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *back;
        Node *next;

    public:
    Node(int data1){
        data = data1;
        back = nullptr;
        next = nullptr;
    }
    Node(int data1, Node *next1 ,Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
};

Node *reverseDLL(Node *head){
    Node *temp = head;
    Node *last = nullptr;
    while(temp != nullptr){
    Node *move = temp->next;
    temp->next = temp->back;
    temp->back = move;
    last = temp;
    temp = temp->back;
    }

    return last;
}

int main(){
    vector<int> arr = {1, 2, 3, 44, 5, 6, 7, 8, 9, 0};
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size();i++){
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        newNode->back = temp;
        temp = temp->next;
    }
    head = reverseDLL(head);
    //traversing
    temp = head;
    while(temp!=nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }

        return 0;
}
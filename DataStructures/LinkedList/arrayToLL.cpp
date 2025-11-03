#include <bits/stdc++.h>
using namespace std;


class Node{
    
    public:
        int data;
        Node *next;

    public:
        Node(int data1, Node*next1){
            data = data1;
            next = next1;
        }
    
    public:
        Node(int data1){
            data = data1;
            next = nullptr;
        }
};


Node * arrConvertToLL(vector<int> &arr){
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size();i++){
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}

void printLL(Node *head){
    
    Node *temp = head;
    while(temp!= nullptr){
        cout << temp->data << ",";
        temp = temp->next;
    }
    cout << "\n";
};

Node *removeHead(Node* head){

    if(head == nullptr){
        return head;
    }

    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
};

Node *removeTail(Node *head){
    Node *temp = head;
    if(head == nullptr){
        return nullptr;
    }
    else if (head->next == nullptr){
        delete(temp);
        return nullptr;
    }
    else{
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        delete(temp->next);
        temp->next = nullptr;
        return head;
    }
}

Node *removeKthElement(Node* head, int k){
    Node *temp = head;
    if (k==0){
        return removeHead(head);
    }
    int count = 0;
    while(temp!=nullptr){
        temp = temp->next;
        count++;
    }
    if(count-1 == k){
        return removeTail(head);
    }
    count = 0;
    temp = head;
    while(count<k){
        temp = temp->next;
        count++;
    }
    Node *skip = temp->next;
    temp->next = temp->next->next;
    delete (skip);
    return
}


int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    Node * head =arrConvertToLL(arr);
    printLL(head);
    head = removeHead(head);
    printLL(head);
    return 0;
};
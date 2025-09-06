#include<bits/stdc++.h> 
using namespace std;

class Node{
    public :
        int data;
        Node *next;
        Node *back;

    public :
    Node (int data1, Node *next1, Node *back1){
        data = data1;
        next = next1;
        back = back1;
    }
    public :
    Node (int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
        }
};

void printDLL(Node *head){
    Node *temp = head;
    while(temp!=nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    //return head;
}

Node *insertHead(Node *head,int val){
    Node *temp = new Node(val,head->next,nullptr);
    Node *remove = head;
    head = temp;
    delete(remove);
    return head;
}


Node *delHeadDLL(Node *head){
    Node *remove = head;
    head = head->next;
    head->back = nullptr;
    delete(remove);
    return head;
}

int main(){
    vector <int>arr = {1, 2, 3, 4, 5, 6};
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size();i++){
        Node *temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }

    printDLL(head);

    return 0;
}
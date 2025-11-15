#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    string data;
    Node *next;
    Node *back;

    public:
    Node(string data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

void insertDLL(Node *&head, Node *&tail,string ch){
    Node *newNode = new Node(ch);
    if(head == nullptr && tail == nullptr){
        head = newNode;
        tail = newNode;
    }
    else{
    newNode->back = tail;
    tail->next = newNode;
    newNode->next = nullptr;
    tail = newNode;
    }
  
}

void printDLL(Node *head){
    Node *temp = head;
    while(temp!=nullptr){
        cout << temp->data;
        temp = temp->next;
    }
}
void insertDLLAtPosition(Node *&head, string val, int index){
    Node *newNode = new Node(val);
    Node *temp = head;
    if(index==1){
        newNode->next = head;
        head->back = newNode;
        head = newNode;
        return;
    }
    int i = 2;
    while(i<index){
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    temp->next->back = newNode;
    newNode->back = temp;
    temp->next = newNode;
}
void deleteDLL(Node *&tail){
    Node *temp = tail;
    tail -> back->next = nullptr;
    delete (temp);
}

Node* deleteDLLAtPosition(Node *&head, int index){
    if (head == nullptr) {
        cout << "List is empty!\n";
        return nullptr;
    }
    Node *temp = head;
    if(index == 1){
        head = head->next;  
        if (head != nullptr){
        head->back = nullptr;
    }
        delete (temp);
        return head;
    }
    int i = 2;
    while (i <= index && temp != nullptr)
    {
        i++;
        temp = temp->next;
    }
        if (temp == nullptr) {
        cout << "Invalid index!\n";
        return head;
    }

      if (temp->back != nullptr)
        temp->back->next = temp->next;
    if (temp->next != nullptr)
        temp->next->back = temp->back;

    delete (temp);
    return head;
}


int main(){
    Node *head = nullptr;
    Node *tail = nullptr;

    string ch[] = {"N","a","m","a","n","d","e","e","p"};
    int sizeArr = sizeof(ch) / sizeof(ch[0]);
    int i = 0;
    for (; i < sizeArr; i++)
    {
        insertDLL(head, tail,ch[i]);
    }

    printDLL(head);
    
    insertDLLAtPosition(head,"13", 1);
    insertDLLAtPosition(head,"October", 3);
    insertDLL(head, tail,"1947");
    cout << "\n";
    printDLL(head);
    head = deleteDLLAtPosition(head, 3);
    head = deleteDLLAtPosition(head, 1);

    deleteDLL(tail);
    cout << "\n";
    printDLL(head);

    return 0;
}


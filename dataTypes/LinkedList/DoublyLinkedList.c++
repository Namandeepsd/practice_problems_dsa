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
    Node *temp = new Node(val,head,nullptr);
    head->back = temp;
    head = temp;
    return head;
}

Node *insertTail(Node *head, int val){
    Node *temp = head;
    while (temp->next != nullptr){
        temp = temp->next;
    }
    Node *newNode = new Node(val, nullptr, temp);
    temp->next = newNode;
    return head;
}

Node *delHeadDLL(Node *head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node *remove = head;
    head = head->next;
    head->back = nullptr;
    delete(remove);
    return head;
}



Node *delTailDLL(Node *head){
    if(head == nullptr){
        return nullptr;
    }
    if(head->next == nullptr){
        delete head;
        return nullptr;
    }
    Node *temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    Node *clear = temp->next;
    temp->next = nullptr;
    clear->back = nullptr;
    delete (clear);
    return head;
    
}
Node *delKthElement(Node *head, int position){
    Node *temp = head;
    if (head == nullptr) return nullptr;

    if(position == 0){
        head = head->next;
        delete (temp);
        return head;
    }
   // temp = temp->next;
    
    for (int i = 1; i <= position && temp->next != nullptr; i++)
    {
        temp = temp->next;
    }
    if( temp->next == nullptr){
        Node *newTail = temp->back;
        temp->back = nullptr;
        newTail->next = nullptr;
        delete (temp);
        return head;
    }
    else{
    Node *last = temp;
    temp->back->next = temp->next;
    temp->next->back = temp->back;
    delete (temp);
    return head;
    }
    
}

// Node * delKthElementLogin2(Node *head, int k){
//     if(head == nullptr){
//         return nullptr;
//     }
//     int cnt = 0;
//     Node *kNode = 0;
//     while(kNode != nullptr){
//         cnt++;
//         if(cnt ==k){
//             break;}
//         kNode = kNode->next;
//     }
//     Node *prev = kNode->back;
//     Node *front = kNode->next;
//     if(prev == nullptr && front  == nullptr){
//         return nullptr;
//     }
//     else if (prev == nullptr){
//         return deleteHea
//     }
// }


int main(){
    vector <int>arr = {1, 2, 3, 4, 5, 6};
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size();i++){
        Node *temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    head = insertTail(head,9);
    printDLL(head);

    return 0;
}
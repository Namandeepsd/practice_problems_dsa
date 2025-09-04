#include<bits/stdc++.h>
using namespace std;
struct Node{
    public:
        int data;
        Node *next;

        public:
        Node(int data1, Node* next1){
            data = data1;
            next = next1;
        }

        public:
        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

Node *convertArr2LL(vector<int> &arr){
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size();i++){
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node *deleteHead(Node *head){
    if(head == NULL ){
        return head;
    }
     Node *temp = head;
    head = head->next;
    delete(temp);
    return head;
}

Node *deleteTail(Node *head, int length){
   // Node *last = head;
   if(head->next == NULL || head== NULL){
       return NULL;
   }

    Node *temp = head;
    for (int i = 0; i < length - 2;i++){
        temp = temp->next;
    }
    Node *last = temp->next;
    temp->next = nullptr;
    free(last);
    return head;
}


Node *deleteTailLogic2(Node *head){
    if(head->next == NULL || head== NULL){
       return NULL;
   }
   Node *temp = head;
   while(temp->next->next!=nullptr){
       temp = temp->next;
   }
   free(temp->next);
   //cout << temp->next->data;
   temp->next = nullptr;
  // cout << temp->next;
   return head;
}

int lengthOfLL(Node* head){
    Node *temp = head;
    int i = 0;
    while(temp!=nullptr){
        i += 1;
        temp = temp->next;
    }
    return i;
}

Node *kthDelete(Node*  head, int position){
    if(head == NULL){
        return head;
    }
    if (position == 0){
        head = deleteHead(head);
    }
    else if (position == lengthOfLL(head)-1){
        head = deleteTailLogic2(head);
    }
    else{
        Node *temp = head;
        for (int i = 0; i < position-1;i++){
            temp = temp->next;
        }
        Node *nodeToFree=temp->next;
        temp->next = temp->next->next;
        delete (nodeToFree);
    }
    return head;
}


Node 

int main(){
    vector<int> arr = {12, 5, 8, 7,6,8,9};
    Node* head = convertArr2LL(arr);
  //  head = deleteHead(head);
    int length = lengthOfLL(head);
    //head = deleteTailLogic2(head);
    head = kthDelete(head, 1);

    // cout << head->data;

   

//    cout << "Length of LL is:" << lengthOfLL(head) << "  ";

     // Traversing
       Node *temp = head;
        while(temp!=nullptr){ 
        cout << temp->data <<" ";
        temp = temp->next;
         
    }

  //  cout << "Tail element is:" << tail->data;
    return 0;
}
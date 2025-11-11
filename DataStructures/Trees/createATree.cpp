#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val){
        data = val;
        left = right = nullptr;
    }
};
void printTree(struct Node* head){
    Node *temp = head;
    cout << temp->data <<",";
    cout << temp->left->data <<",";
    cout << temp->right->data <<",";
    cout << temp->left->right->data <<",";
}

int main(){
    struct Node *root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);
    printTree(root);
    return 0;
}
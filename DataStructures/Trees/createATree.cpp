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
void inOrderTreeTraversal(struct Node* node){
    if(node == nullptr){
        return ;
    }
      inOrderTreeTraversal(node->left);
    cout << node->data << ",";
      inOrderTreeTraversal(node->right);
    
}

void postOrderTreeTraversal(struct Node* node){
    if(node==nullptr){
        return;
    }
    postOrderTreeTraversal(node->left);
    postOrderTreeTraversal(node->right);
    cout << node->data <<"->";
}

void preOrderTreeTraversal(struct Node* node){
    if(node==nullptr){
        return;
    }
    cout << node->data << "-";
    preOrderTreeTraversal(node->left);
    preOrderTreeTraversal(node->right);
}


int main(){
    struct Node *root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(5);

    cout << "In Order Traversal \n";
    inOrderTreeTraversal(root);
    cout << "\nPost Order Traversal \n";
    postOrderTreeTraversal(root);
    cout << "\nPre Order Traversal \n";
    preOrderTreeTraversal(root);
    return 0;
}
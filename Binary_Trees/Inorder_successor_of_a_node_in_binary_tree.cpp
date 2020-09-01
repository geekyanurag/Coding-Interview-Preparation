#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left, *right;
};

Node* insert(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
}

// Finding the node which comes after a given node in inorder traversal of tree.
// Idea is to do the reverse inorder traversal.
void inorderSuccessor(Node* root, Node* target_node, Node* &next){
    if(!root) return;

    inorderSuccessor(root->right, target_node, next);

    if(root->data == target_node->data){
        if(next == NULL){
            cout<<"inorder successor of "<<root->data<<" is NULL"<<endl;
        }
        else{
            cout<<"inorder successor of "<<root->data<<" is "<<next->data<<endl;
        }
    }
    next = root;
    inorderSuccessor(root->left, target_node, next);
}

int main(){
    Node* root = insert(1);
    root->left = insert(2);
    root->right = insert(3);
    root->left->left = insert(4);
    root->left->right = insert(5);
    root->right->left = insert(6);
    root->right->right = insert(7);
    Node* next = NULL;
    inorderSuccessor(root, root->left->left, next);
}
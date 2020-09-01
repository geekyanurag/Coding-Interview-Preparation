#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left, *right;
    bool isThreaded;
};

Node* insert(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
// Threaded binary tree is a binary tree whose all NULL right pointers point to the inorder successor (if exists).
Node* createThreaded(Node* root){
    if(!root) return NULL;

    if(!root->left && !root->right) return root;

    if(root->left){
        Node* l = createThreaded(root->left);

        l->right = root;
        l->isThreaded = true;
    }
    if(!root->right) return root;

    return createThreaded(root->right);
}

Node* leftMost(Node* root){
    while(root && root->left)
        root = root->left;
    return root;
}

void inorder(Node* root){
    if(!root) return;

    Node* cur = leftMost(root);
    while(cur){
        cout<<cur->data<<" ";

        if(cur->isThreaded)
            cur = cur->right;
        else
            cur = leftMost(cur->right);
    }
}

int main(){
    Node* root = insert(1);
    root->left = insert(2);
    root->right = insert(3);
    root->left->left = insert(4);
    root->left->right = insert(5);
    root->right->left = insert(6);
    root->right->right = insert(7);
    createThreaded(root);
    inorder(root);
    return 0;
}
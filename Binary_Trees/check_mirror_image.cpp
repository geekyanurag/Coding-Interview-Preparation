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

void printTree(Node* root){
    if(root == NULL)
        return;
    printTree(root->left);
    cout<<root->data<<" ";
    printTree(root->right);
}

bool isIdentical(Node* root1, Node* root2){
    if(!root1 && !root2)
        return true;
    if(!root1 || !root2)
        return false;
    if(root1->data == root2->data && isIdentical(root1->left, root2->right) && isIdentical(root1->right, root2->left))
        return true;
    else
        return false;
}

int main(){
    Node* root = insert(9);
    root->left = insert(2);
    root->right = insert(4);
    root->left->left = insert(5);
    root->left->right = insert(3);
    root->right->left = insert(8);
    Node* root2 = insert(9);
    root2->left = insert(4);
    root2->right = insert(2);
    root2->right->right = insert(5);
    root2->left->right = insert(8);
    root2->right->left = insert(3);
    //printTree(root);
    bool res = isIdentical(root, root2);
    cout<<res;
    return 0;
}
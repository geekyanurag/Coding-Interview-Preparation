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
// each node is sum of its left child and right child only not the sum of its grandchildrens.
bool isSum(Node* root){
    if(!root || (!(root->left) && !(root->right)))
        return true;
    int ls = 0, rs = 0;
    if(root->left)
        ls = root->left->data;
    if(root->right)
        rs = root->right->data;
    if((root->data == (ls+rs)) && isSum(root->left) && isSum(root->right))
        return true;
    return false;
}

void printTree(Node* root){
    if(root == NULL)
        return;
    printTree(root->left);
    cout<<root->data<<" ";
    printTree(root->right);
}

int main(){
    Node* root = insert(12);
    root->left = insert(9);
    root->right = insert(3);
    root->left->left = insert(4);
    root->left->right = insert(5);
    root->right->left = insert(2);
    root->right->right = insert(1);
    //printTree(root);
    bool res = isSum(root);
    cout<<res;
    return 0;
}
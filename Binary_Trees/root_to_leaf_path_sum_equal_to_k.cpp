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

bool issum(Node* root, int sum){
    if(root == NULL)
        return false;
    if(!root->left && !root->right){
        if(root->data == sum)
            return true;
        else
            return false;
    }
    if(issum(root->left, sum - root->data) || issum(root->right, sum - root->data))
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
    Node* root = insert(9);
    root->left = insert(2);
    root->right = insert(4);
    root->left->left = insert(5);
    root->left->right = insert(3);
    root->right->left = insert(8);
    //printTree(root);
    bool res = issum(root, 21);
    cout<<res;
    return 0;
}
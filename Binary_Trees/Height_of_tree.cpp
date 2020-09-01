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
    return temp;
}

// Idea is for every node the height will be 1 + max(left_height, right_height).
int height(Node* root){
    if(!root) return 0;

    int left_height = height(root->left);
    int right_height = height(root->right);

    return 1 + max(left_height, right_height);
}

int main(){
    Node* root = insert(3);
    root->left = insert(4);
    root->right = insert(5);
    root->left->left = insert(6);
    root->right->left = insert(8);
    int res = height(root);
    cout<<res<<endl;
    return 0;
}
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

void inorder(Node* root){
    if(root == NULL)
        return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
    Node* root = insert(1);
    root->left = insert(2);
    root->right = insert(3);
    root->left->left = insert(4);
    root->right->left = insert(5);
    root->left->right = insert(6);
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);

}
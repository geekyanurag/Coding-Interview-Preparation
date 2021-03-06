#include<bits/stdc++.h>
using namespace std;

//creating a Node structure
struct Node{
    int data;
    Node* left, *right;
};

//insert operation
Node* insert(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

//inorder traversal to print the tree
void print(Node* head){
    if(head == NULL)
        return;
    print(head->left);
    cout<<head->data<<" ";
    print(head->right);
}

int main(){
    Node* head = insert(1);
    head->left = insert(2);
    head->right = insert(3);
    head->left->left = insert(4);
    print(head);
    return 0;
}
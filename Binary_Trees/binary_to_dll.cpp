#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left, *right;
};

Node* insert(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void convertdll(Node* root, Node** head){
    if(root == NULL)
        return; 
    convertdll(root->right, head);
    root->right = *head;
    if(*head != NULL)
        (*head)->left = root;
    *head = root;
    convertdll(root->left, head);
}
void printTree(Node* root){
    if(root == NULL)
        return;
    printTree(root->left);
    cout<<root->data<<" ";
    printTree(root->right);
}

void printDll(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->right;
    }
}
int main(){
    Node* root = insert(9);
    root->left = insert(3);
    root->right = insert(4);
    root->left->left = insert(5);
    root->left->right = insert(1);
    root->right->left = insert(8);
    printTree(root);
    cout<<endl;
    Node* head = NULL;
    convertdll(root, &head);
    printDll(head);
    return 0;
}
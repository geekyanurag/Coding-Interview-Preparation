#include<bits/stdc++.h>
using namespace std;

// Given a tree and we have to convert it to doubly linked list.
/*
                                10
							  /    \
							12     15
						  /  \     /
						 25  30   36

		25 <-> 12 <-> 30 <-> 10 <-> 36 <-> 15
*/
struct Node{
    int data;
    Node* left, *right;
};

void BtoDLL(Node* root, Node** head){
    if(root == NULL)
        return;
    
    BtoDLL(root->right, head);
    root->right = *head;

    if(*head != NULL)
        (*head)->left = root;
    
    *head = root;

    BtoDLL(root->left, head);
}

Node* insert(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->right;
    }
}

int main(){
    Node* root = insert(5);
    root->left = insert(3);
    root->right = insert(6);
    root->left->left = insert(1);
    root->left->right = insert(4);
    root->right->right = insert(8);
    root->left->left->left = insert(0);
    root->left->left->right = insert(2);
    root->right->right->left = insert(7);
    root->right->right->right = insert(9);
    Node* head = NULL;
    BtoDLL(root, &head);
    print(head);
}
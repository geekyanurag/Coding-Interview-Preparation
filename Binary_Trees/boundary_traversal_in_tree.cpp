//Boundary traversal in anticlockwise direction
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

// Boundary traversal of a binary tree
void printLeftBoundary(Node* root){
    if(root){
        if(root->left){
            cout<<root->data<<" ";
            printLeftBoundary(root->left);
        }
        else if(root->right){          // if left child of a node doesn't exists then go for right child
            cout<<root->data<<" ";
            printLeftBoundary(root->right);
        }
    }
}

void printRightBoundary(Node* root){
    if(root){
        if(root->right){
            printRightBoundary(root->right);     //anticlockwise so first go to extreme right then print
            cout<<root->data<<" ";
        }
        else if(root->left){
            printRightBoundary(root->left);
            cout<<root->data<<" ";
        }
    }
}

void printLeaves(Node* root){
    if(root == NULL)
        return ;
    printLeaves(root->left);
    if(root->left == NULL && root->right == NULL)
        cout<<root->data<<" ";
    printLeaves(root->right); 
}

void printBoundary(Node* root){
    if(root == NULL)
        return; 
    cout<<root->data<<" ";
    printLeftBoundary(root->left);
    printLeaves(root->left);
    printLeaves(root->right);
    printRightBoundary(root->right);
}
/*void printTree(Node* root){
    if(root == NULL)
        return;
    printTree(root->left);
    cout<<root->data<<" ";
    printTree(root->right);
}
*/

int main(){
    Node* root = insert(9);
    root->left = insert(2);
    root->right = insert(4);
    root->left->left = insert(5);
    root->left->right = insert(3);
    root->right->left = insert(8);
    //printTree(root);
    printBoundary(root);
    return 0;
}
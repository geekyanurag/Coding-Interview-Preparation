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

int countNodes(Node* root){
    if(root == NULL)
        return 0;
    return (1 + countNodes(root->left) + countNodes(root->right));
}

bool isComplete(Node* root, int index, int numNodes){
    if(root == NULL)
        return true;
    if(index >= numNodes)
        return false;
    return (isComplete(root->left, 2*index + 1, numNodes)  && isComplete(root->right, 2 * index + 2, numNodes));
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
    //root->left->right = insert(3);
    root->right->left = insert(8);
    int count = countNodes(root);
    bool res = isComplete(root, 0, count);
    cout<<res;
    //printTree(root);
    return 0;
}
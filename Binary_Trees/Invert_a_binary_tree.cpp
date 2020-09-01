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

// Recursive approach
// Invert tree means that converting the tree into its mirror image.
void invertTree(Node* root){
    if(!root) return;

    else{
        Node* temp;

        invertTree(root->left);
        invertTree(root->right);

        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

// Iterative approach

void invertTreeIterative(Node* root){
    if(!root) return;

    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        swap(temp->left, temp->right);

        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);

    }
}
void printInorder(Node* root){
    if(root == NULL)
        return;
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main(){
    Node* root = insert(1);
    root->left = insert(2);
    root->right = insert(3);
    root->left->left = insert(4);
    root->left->right = insert(5);
    invertTree(root);
    printInorder(root);
    cout<<endl;
    invertTreeIterative(root);
    printInorder(root);
    return 0;
}
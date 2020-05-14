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
// Merging takes place by sum of the nodes whose values is equal otherwise take the node which is not null
Node* merge(Node* root1, Node* root2){
    if(!root1)
        return root2;
    if(!root2)
        return root1;
    root1->data += root2->data;
    root1->left = merge(root1->left, root2->left);
    root1->right = merge(root1->right, root2->right);
    return root1;
}

void preorder(Node* root){
    if(!root)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    Node* root1 = insert(2);
    root1->left = insert(1);
    root1->right = insert(4);
    root1->left->left = insert(5);

    Node* root2 = insert(3);
    root2->left = insert(6);
    root2->right = insert(1);
    root2->right->right = insert(7);
    root2->left->right = insert(2);

    // Merging return the root of the merged tree
    root1 = merge(root1, root2);
    preorder(root1);
}

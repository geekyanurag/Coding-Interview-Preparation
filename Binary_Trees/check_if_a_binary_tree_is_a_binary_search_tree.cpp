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
// First Approach
/*
bool isSubtreeLesser(Node* root, int val){
    if(root == NULL)
        return true;
    if(root->data < val && isSubtreeLesser(root->left, val) && isSubtreeLesser(root->right, val))
        return true;
    else 
        return false;
}

bool isSubtreeGreater(Node* root, int val){
    if(root == NULL)
        return true;
    if(root->data > val && isSubtreeGreater(root->left, val) && isSubtreeGreater(root->right, val) )
        return true;
    else
        return false;
}

bool isBst(Node* root){
    if(root == NULL)
        return true;
    if(isSubtreeLesser(root->left, root->data) && isSubtreeGreater(root->right, root->data) && isBst(root->left) && isBst(root->right))
        return true;
    else
        return false;
}
*/
//Another approach taking min and max values

bool isBstUtil(Node* root, int minval, int maxval){
    if(root == NULL)
        return true;
    if(root->data < minval || root->data > maxval)
        return false;
    return isBstUtil(root->left, minval, root->data-1) && isBstUtil(root->right, root->data+1, maxval);  //Allow distinct values
}

bool isBst(Node* root){
    return (isBstUtil(root, INT_MIN, INT_MAX));
}

void printTree(Node* root){
    if(root == NULL)
        return;
    printTree(root->left);
    cout<<root->data<<" ";
    printTree(root->right);
}

int main(){
    Node* root = insert(4);
    root->left = insert(2);
    root->right = insert(5);
    root->left->left = insert(1);
    root->left->right = insert(3);
    //root->right->left = insert(8);
    //printTree(root);
    bool res = isBst(root);
    cout<<res;
    return 0;
}
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
// First Approach O(n*n) complexity
int sum(Node* root){
    if(root == NULL)
        return 0;
    return sum(root->left) + root->data + sum(root->right);
}

bool isSumTree(Node* root){
    int ls, rs;
    if(root == NULL || (root->left == NULL && root->right == NULL))
        return true;
    ls = sum(root->left);
    rs = sum(root->right);
    if(root->data == (ls+rs) && isSumTree(root->left) && isSumTree(root->right))
        return true;
    return false;
}

//Another Approach O(n) complexity
/*
bool isLeaf(Node* root){
    if(root == NULL)
        return false;
    if(!root->left && !root->right)
        return true;
    return false;
}

bool isSumTree(Node* root){
    int ls, rs;
    if(root == NULL || isLeaf(root))
        return true;
    if(isSumTree(root->left) && isSumTree(root->right)){
        if(root->left == NULL)
            ls = 0;
        else if(isLeaf(root->left))
            ls = root->left->data;
        else
            ls = 2 * root->left->data;

        if(root->right == NULL)
            rs = 0;
        else if(isLeaf(root->right))
            rs = root->right->data;
        else
            rs = 2 * root->right->data;
        return root->data == ls+rs;
    }
    return 0;
}
*/

void printTree(Node* root){
    if(root == NULL)
        return;
    printTree(root->left);
    cout<<root->data<<" ";
    printTree(root->right);
}

int main(){
    Node* root = insert(24);
    root->left = insert(9);
    root->right = insert(3);
    root->left->left = insert(5);
    root->left->right = insert(4);
    root->right->left = insert(2);
    root->right->right = insert(1);
    bool res = isSumTree(root);
    cout<<res;
    //printTree(root);
    return 0;
}
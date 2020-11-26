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
//Simple Solution O(n*n)
int max(int a, int b){
    return a >= b ? a : b;
}
int height(Node* root){
    if(root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(Node* root){
    int lh, rh;
    if(root == NULL)
        return 1;
    lh = height(root->left);
    rh = height(root->right);

    if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;
    return 0;
}

//Optimized solution O(n) complexity. Calculating height in the same function
bool isBalanced1(Node* root, int* height){
    int lh = 0, rh = 0;
    int l = 0, r = 0;
    if(root == NULL){
        *height = 0;
        return true;
    }
    l = isBalanced1(root->left, &lh);
    r = isBalanced1(root->right, &rh);
    *height = (lh > rh ? lh : rh ) + 1;
    if(abs(lh - rh) > 1)
        return false;
    else 
        return l && r;
}

// Same algorithms can be implemented like this :-
// If the ith node's left subtree is balanced or not. If it is then return the height of the left subtree and similarly if ith node's right subtree is balanced
// or not if yes then return height of right subtree. Then for ith node we will check if it is height balanced or not if it is then return the height of it.
int isBalanced2(Node* root){
    if(!root) return 0;

    int lh = isBalanced2(root->left);
    if(lh == -1){
        return -1;
    }
    int rh = isBalanced2(root->right);
    if(rh == -1){
        return -1;
    }
    if(abs(lh - rh) > 1) return -1;

    return 1 + max(lh, rh);
}

void printTree(Node* root){
    if(root == NULL)
        return;
    printTree(root->left);
    cout<<root->data<<" ";
    printTree(root->right);
}

int main(){
    int height = 0;
    Node* root = insert(9);
    root->left = insert(2);
    root->right = insert(4);
    root->left->left = insert(5);
    root->left->right = insert(3);
    root->right->left = insert(8);
    //printTree(root);
    bool res = isBalanced(root);
    //bool res = isBalanced(root, &height);
    cout<<res;
    return 0;
}
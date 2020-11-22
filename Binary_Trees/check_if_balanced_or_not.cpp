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
/*bool isBalanced(Node* root, int* height){
    int lh = 0, rh = 0;
    int l = 0, r = 0;
    if(root == NULL){
        *height = 0;
        return true;
    }
    l = isBalanced(root->left, &lh);
    r = isBalanced(root->right, &rh);
    *height = (lh > rh ? lh : rh ) + 1;
    if(abs(lh - rh) > 1)
        return false;
    else 
        return l && r;
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
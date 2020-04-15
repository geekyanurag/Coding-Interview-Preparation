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
//O(n*n) Complexity Solution
bool isIdentical(Node* root1, Node* root2){
    if(!root1 && !root2)
        return true;
    if(!root1 || !root2)
        return false;
    if(root1->data == root2->data && isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right))
        return true;
    return false;
}

bool isSubtree(Node* s, Node* t){
    if(s == NULL)
        return true;
    if(t == NULL)
        return false;
    if(isIdentical(s, t))
        return true;
    return isSubtree(s, t->left) || isSubtree(s, t->right);
}
// O(n) Approach
bool isSubtree(Node* s, Node* t){
    if(s == NULL)
        return true;
    if(t == NULL)
        return true;
    char inS[100], inT[100];
    int i = 0, j = 0;
    inorder(s, inS, i);
    inorder(t, inT, j);
    inS[i] = '\0';
    inT[j] = '\0';
    if(strstr(inT, inS) == false)
        return false;    
    i = 0, j = 0;
    char preS[100], preT[100];
    preorder(s, preS, i);
    preorder(t, preT, j);
    preS[i] = '\0';
    preT[j] = '\0';
    if(strstr(preT, preS) == false)
        return false;
    return true;
}

void inorder(Node* root, char arr[], int i){
    if(root == NULL)
        return;
    inorder(root->left, arr, i);
    inS[i++] = root->data;
    inorder(root->right, arr, i);
}

void preorder(Node* root, char arr[], int i){
    if(root == NULL)
        return;
    preorder(root->left, arr, i);
    inT[i++] = root->data;
    preorder(root->right, arr, i);
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
    root->left->right = insert(3);
    root->right->left = insert(8);
    Node* root2 = insert(2);
    root2->left = insert(5);
    root2->right = insert(3);
    bool res = isSubtree(root2, root);
    cout<<res;
    //printTree(root);
    return 0;
}
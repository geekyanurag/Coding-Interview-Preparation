#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left, *right;
};

bool isIdentical(Node* root1, Node* root2){
    if(!root1 && !root2) return true;
    if(!root1 || !root2) return false;

    if(root1->data == root2->data && isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right)) return true;
    else return false;

}

Node* insert(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void printInorder(Node* root){
    if(root == NULL)
        return;
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}

int main(){
    Node* root1 = insert(3);
    root1->left = insert(4);
    root1->right = insert(5);
    root1->left->left = insert(6);
    root1->right->left = insert(8);
    Node* root2 = insert(3);
    root2->left = insert(4);
    root2->right = insert(5);
    root2->left->left = insert(6);
    root2->right->left = insert(8);
    if(isIdentical(root1, root2))
        cout<<"Yes"<<endl;
    else 
        cout<<"No"<<endl;
    //printInorder(root);
    return 0;
}
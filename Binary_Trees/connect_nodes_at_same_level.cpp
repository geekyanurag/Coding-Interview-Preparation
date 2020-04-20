#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left, *right, *nextright;
};

Node* insert(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
}

void connect(Node* root){
    Node* prev, *curr;
    queue<Node*>q;
    q.push(root);
    int count = 0;
    while(!q.empty()){
        prev = NULL;
        count = q.size();
        while(count--){
            curr = q.front();
            q.pop();
            if(prev != NULL)
                prev->nextright = curr;
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
            prev = curr;
        }
        curr->nextright = NULL;
    }
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
    connect(root);
    //printTree(root);
    return 0;
}    
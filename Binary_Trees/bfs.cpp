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

void bfs(Node* root){
    queue<Node*>q;
    q.push(root);
    Node* temp;
    while(!q.empty()){
        temp = q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
}

int main(){
    Node* root = insert(8);
    root->left = insert(7);
    root->right = insert(6);
    root->left->left = insert(5);
    root->left->right = insert(4);
    root->right->left = insert(3);
    root->right->right = insert(1);
    bfs(root);
    return 0;
}

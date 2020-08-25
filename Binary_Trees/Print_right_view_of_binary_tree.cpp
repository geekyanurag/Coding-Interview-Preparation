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

// Recursive Solution
void printRightView(Node* root, int level, int &maxLength){
    if(!root) return;

    if(maxLength < level){
        cout<<root->data<<" ";
        maxLength = level;
    }

    printRightView(root->right, level + 1, maxLength); // First visits right because taking last node of a given level.
    printRightView(root->left, level + 1, maxLength);
}

void print(Node* root){
    int maxLength = 0;
    printRightView(root, 1, maxLength);
}

// Iterative Solution
// Doing level order traversal and printing last node of a given level.
void printRightViewIterative(Node* root){
    if(!root) return;

    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        for(int i = 1; i<=n; i++){
            Node* temp = q.front();
            q.pop();
            if(i == n)
                cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}

int main(){
    Node* root = insert(3);
    root->left = insert(4);
    root->right = insert(5);
    root->left->left = insert(6);
    root->right->left = insert(8);
    root->right->right = insert(2);
    print(root);
    cout<<endl;
    printRightViewIterative(root);
    return 0;
}
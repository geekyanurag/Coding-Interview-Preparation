#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left, *right;
};

Node* newNode(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Recursive Solution
// checking if level of the current node is greater than the previous node then print the first node having that level.
void printLeftView(Node* root, int level, int &maxLevel){
    if(!root) return;
    
    if(maxLevel < level){
        cout<<root->data<<" ";
        maxLevel = level;
    }
    printLeftView(root->left, level + 1, maxLevel);
    printLeftView(root->right, level + 1, maxLevel);
}

void print(Node* root){
    int maxLevel = 0;
    printLeftView(root, 1, maxLevel);
}

// Iterative method
// using bfs or level order traversal and then print the first node.
void printLeftViewIterative(Node* root){
    if(!root) return;

    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        if(temp){
            cout<<temp->data<<" ";
            while(temp != NULL){
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                q.pop();
                temp = q.front();
            }
            q.push(NULL);
        }
        q.pop();
    }
}

int main(){
    Node* root = newNode(3);
    root->left = newNode(1);
    root->right = newNode(4);
    root->left->left = newNode(5);
    root->right->left = newNode(7);
    root->right->right = newNode(9);
    root->left->right = newNode(8);
    print(root);
    cout<<endl;
    printLeftViewIterative(root);
    return 0;
}
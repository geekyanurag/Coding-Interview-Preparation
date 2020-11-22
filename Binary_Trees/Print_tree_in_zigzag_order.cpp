#include<bits/stdc++.h>
using namespace std;

// Print tree in zigzag order
 /*         7
        /     \
       9       7
     /  \     /   
    8    8   6     
   /  \
  10   9 
  output - 7 7 9 8 8 6 9 10 (starting from first level from left to right then for next level right to level then again next level left to right and so on....)
*/

// Idea is to take two stacks and then do bfs then add root to curr level and then all its childrens to next level and then swap curr level and next level if curr level is empty.
struct Node{
    int data;
    Node* left, *right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void zigzag(Node* root){
    if(!root) return;
    stack<Node*>currLevel;
    stack<Node*>nextLevel;
    currLevel.push(root);
    bool lefttoright = true;
    while(!currLevel.empty()){
        Node* temp = currLevel.top();
        currLevel.pop();
        
        if(temp){
            cout<<temp->data<<" ";
            if(lefttoright){
                if(temp->left) nextLevel.push(temp->left);
                if(temp->right) nextLevel.push(temp->right);
            }
            else{
                if(temp->right) nextLevel.push(temp->right);
                if(temp->left) nextLevel.push(temp->left);
            }
        }
        if(currLevel.empty()){
            lefttoright = !lefttoright;
            swap(currLevel, nextLevel);
        }
    }
}

void print(Node* root){
    if(!root) return ;
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    zigzag(root);
    //print(root);
    return 0;
}
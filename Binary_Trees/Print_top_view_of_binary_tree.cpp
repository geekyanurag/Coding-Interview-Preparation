#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data, hd;
    Node* left, *right;
};

Node* insert(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Idea is to calculate horizontal distance for node ie its left child distance is dist(node) - 1 and its right child's distance is dist(node) + 1.
// Same concept used in printing nodes in vertical order.
void printTopView(Node* root){
    if(!root) return;

    int hd = 0;
    queue<Node*>q;
    map<int,int>mp;
    root->hd = hd;
    q.push(root);

    while(!q.empty()){
        hd = root->hd;

        if(mp.count(hd) == 0)
            mp[hd] = root->data;
        
        if(root->left){
            root->left->hd = hd - 1;
            q.push(root->left);
        }
        if(root->right){
            root->right->hd = hd + 1;
            q.push(root->right);
        }
        q.pop();
        root = q.front();
    }

    for(auto i : mp)
        cout<<i.second<<" ";
}

int main(){
    Node* root = insert(3);
    root->left = insert(2);
    root->right = insert(1);
    root->left->left = insert(6);
    root->left->right = insert(8);
    root->right->left = insert(9);
    root->right->right = insert(4);

    printTopView(root);
}
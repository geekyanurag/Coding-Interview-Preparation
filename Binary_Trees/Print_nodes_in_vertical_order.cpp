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

// Calculating horizontal distance from root having left child as distance dist(root) - 1 and right child's distance is dist(root) + 1. Storing all the nodes data in map having same horizontal distance.
// Same as printing top view of binary tree.
void getVerticalOrder(Node* root, int hd, map<int, vector<int>>&mp){
    if(!root) return;

    mp[hd].push_back(root->data);

    getVerticalOrder(root->left, hd - 1, mp);
    getVerticalOrder(root->right, hd + 1, mp);
}

void printVerticalOrder(Node* root){
    int hd = 0;
    map<int, vector<int>>mp;
    getVerticalOrder(root, hd, mp);

    for(auto i : mp){
        for(auto j : mp[i.first]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main(){
    Node* root = insert(3);
    root->left = insert(4);
    root->right = insert(5);
    root->left->left = insert(6);
    root->right->left = insert(8);
    printVerticalOrder(root);
    return 0;
}
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

// Diameter is number of nodes in longest path between two leaf nodes.
// Idea is to calculate height and update a variable say res which will store the diameter because diameter is nothing but (1 + left_height + right_height) for every node. So return the max of res.
int diameter(Node* root, int &res){
    if(!root)
        return 0;
    int lh = diameter(root->left, res);
    int rh = diameter(root->right, res);

    res = max(res, 1 + lh + rh);

    return 1 + max(lh, rh);
}

int main(){
    Node* root = insert(3);
    root->left = insert(4);
    root->right = insert(5);
    root->left->left = insert(7);
    root->left->right = insert(1);
    int d = INT_MIN;
    int res = diameter(root, d);
    cout<<d<<endl;
    return 0;
}
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

// Recursive solution which is only true when both the nodes are present in the tree.
Node* lca(Node* root, int a, int b){
    if(!root) return NULL;

    if(root->data == a || root->data == b) return root;

    Node* l = lca(root->left, a, b);
    Node* r = lca(root->right, a, b);

    if(l && r) return root;

    return (l ? l : r);
}

// Better Approach
// Taking v1 and v2 where it will store whether both the nodes are present in the tree or not. If not present then lca will be NULL.

Node* findLca(Node* root, int a, int b, bool &v1, bool &v2){
    if(!root) return NULL;
    
    if(root->data == a){
        v1 = true;
        return root;
    }

    if(root->data == b){
        v2 = true;
        return root;
    }

    Node* l = findLca(root->left, a, b, v1, v2);
    Node* r = findLca(root->right, a, b, v1, v2);

    if(l && r) return root;

    return (l ? l : r);
}

bool find(Node* root, int k){
    if(!root) return false;

    if(root->data == k || find(root->left, k) || find(root->right, k))
        return true;
    
    return false;
}

Node* lca1(Node* root, int a, int b){
    if(!root) return NULL;

    bool v1 = false, v2 = false;

    Node* lca2 = findLca(root, a, b, v1, v2);

    if(v1 && v2 || v1 && find(lca2, b) || v2 && find(lca2, a))  // v1 && v2 means if both nodes are present, v1 && find(lca2, b) means if first node is present and if b is present in the subtree having root as lca and similarly v2 && find(lca2, a) means.
        return lca2;
    
    return NULL;
}

int main(){
    Node* root = insert(3);
    root->left = insert(4);
    root->right = insert(5);
    root->left->left = insert(6);
    root->right->left = insert(8);
    Node* res = lca(root, 6, 8);
    Node* res1 = lca1(root, 6, 8);
    cout<<res->data<<endl;
    cout<<res1->data<<endl;
    return 0;
}
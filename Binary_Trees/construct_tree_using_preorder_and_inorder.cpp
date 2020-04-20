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

int search(int in[], int l, int r, int x){
    /*while(l<=r){            // Using binary Search
        int mid = (l + r) / 2;
        if(x == in[mid])
            return mid;
        else if(x > in[mid])
            l = mid + 1;
        else
            r = mid-1;
    }
    */
   for(int i =l; i<=r; i++){      //Using Linear Search
       if(in[i] == x)
        return i;
   }
}
Node* buildTree(int in[], int pre[], int instart, int inend){
    static int preindex = 0;
    if(instart > inend)
        return NULL;
    Node* temp = insert(pre[preindex++]);
    if(instart == inend)
        return temp;
    int inIndex = search(in, instart, inend, temp->data);
    temp->left = buildTree(in, pre, instart, inIndex-1);
    temp->right = buildTree(in, pre, inIndex+1, inend);
    return temp;
}
void printTree(Node* root){
    if(root == NULL)
        return;
    printTree(root->left);
    cout<<root->data<<" ";
    printTree(root->right);
}
int main(){
    int in[] = {5, 2, 3, 9, 8, 4};
    int pre[] = {9, 2, 5, 3, 4, 8};
    int len = sizeof(in)/sizeof(in[0]);
    Node* root = buildTree(in, pre, 0, len);
    printTree(root);
    return 0;
}
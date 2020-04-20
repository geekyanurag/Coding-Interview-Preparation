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

void deletion(Node* root, Node* d_node){      //Method for deleting the last node
    queue<Node*>q;
    q.push(root);
    Node* temp;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp == d_node){
            temp = NULL;
            delete(d_node);
            return;
        }
        if(temp->right){
            if(temp->right == d_node){
                temp = NULL;
                delete(d_node);
                return;
            }
            else
                q.push(temp->left);
        }
        if(temp->left){
            if(temp->left == d_node){
                temp = NULL;
                delete(d_node);
                return;
            }
            else 
                q.push(temp->right);
        }
    }
}

Node* deleteKey(Node* root, int key){
    if(root == NULL)
        return NULL;
    if(!root->left && !root->right){
        if(root->data == key)
            return NULL;
        else
            return root;
    }
    queue<Node*>q;
    q.push(root);
    Node* temp;
    Node* key_node = NULL;
    while(!q.empty()){       //Finding the node to be deleted and store it in key_node
        temp = q.front();
        q.pop();
        if(temp->data == key){
            key_node = temp;
        }
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right)
            q.push(temp->right);
    }
    //when loop ends temp points to the last node and its value is replaced by the deleted node and then delete the last node
    if(key_node != NULL){
        int x = temp->data;
        deletion(root, temp);
        key_node->data = x;
    }
    return root;
}
void printTree(Node* root){
    if(root == NULL)
        return;
    printTree(root->left);
    cout<<root->data<<" ";
    printTree(root->right);
}

int main(){
    Node* root = insert(8);
    root->left = insert(7);
    root->right = insert(6);
    root->left->left = insert(5);
    root->left->right = insert(4);
    root->right->left = insert(3);
    root->right->right = insert(1);
    root = deleteKey(root, 7);
    printTree(root);
    return 0;
}
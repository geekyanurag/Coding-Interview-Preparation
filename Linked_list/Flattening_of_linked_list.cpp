#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* down, *right;
};

// We used the merge technique in merge sort to flattent the list. Since the list contains vertical and right pointers so the right pointer
// will used as pointer of another list and first list will be the vertical one. Then recursively do it for rest of the list.
Node* merge(Node* a, Node* b){
    Node* result = NULL;

    if(a == NULL)
        return b;
    else if(b == NULL)
        return a;
    
    if(a->data <= b->data){
        result = a;
        result->down = merge(a->down, b);
    }
    else{
        result = b;
        result->down = merge(a, b->down);
    }
    result->right = NULL;
    return result;
}

Node* flatten(Node* head){
    
    if(head == NULL || head->right == NULL)
        return head;
    
    return merge(head, flatten(head->right));
}

void insert(Node** head, int data){
    Node* temp = new Node();
    temp->data = data;
    temp->right = NULL;
    temp->down = *head;
    *head = temp;
}

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->down;
    }
}

int main(){
    Node* head = NULL;
    insert( &head, 30 ); 
    insert( &head, 8 ); 
    insert( &head, 7 ); 
    insert( &head, 5 ); 
  
    insert( &( head->right ), 20 ); 
    insert( &( head->right ), 10 ); 
  
    insert( &( head->right->right ), 50 ); 
    insert( &( head->right->right ), 22 ); 
    insert( &( head->right->right ), 19 ); 
  
    insert( &( head->right->right->right ), 45 ); 
    insert( &( head->right->right->right ), 40 ); 
    insert( &( head->right->right->right ), 35 ); 
    insert( &( head->right->right->right ), 20 ); 
    Node* res = flatten(head);
    print(res);
    return 0;
}
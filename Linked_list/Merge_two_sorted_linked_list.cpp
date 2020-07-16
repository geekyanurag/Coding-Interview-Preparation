#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void MoveNode(Node**, Node**);

// Recursive Solution
Node* merge(Node* a, Node* b){
    Node* result = NULL;

    if(a == NULL)
        return b;
    else if(b == NULL)
        return a;
    
    if(a->data <= b->data){
        result = a;
        result->next = merge(a->next, b);
    }
    else{
        result = b;
        result->next = merge(a, b->next);
    }
    return result;
}

// Iterative Solution
Node* mergeIterative(Node* a, Node* b){
    Node dummy;
    Node* tail = &dummy;

    dummy.next = NULL;
    while(1){
        if(a == NULL){
            tail->next = b;
            break;
        }
        else if(b == NULL){
            tail->next = a;
            break;
        }

        if(a->data <= b->data)
            MoveNode(&(tail->next), &a);
        else 
            MoveNode(&(tail->next), &b);
        
        tail = tail->next;
    }
    return dummy.next;
}

void MoveNode(Node** dest, Node** src){
    Node* temp = *src;

    if(temp == NULL)
        return; 

    *src = temp->next;
    temp->next = *dest;
    *dest = temp;
}

void insert(Node** head, int data){
    Node* temp = new Node();
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

void print(Node* head){
    Node* temp = head;

    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    Node* head1 = NULL, *head2 = NULL;
    insert(&head1, 5);
    insert(&head1, 2);
    insert(&head1, 1);
    insert(&head2, 6);
    insert(&head2, 4);
    insert(&head2, 3);
    Node* res = merge(head1, head2);
    Node* res1 = mergeIterative(head1, head2);
    print(res);
    cout<<endl;
    print(res1);
    return 0;
}
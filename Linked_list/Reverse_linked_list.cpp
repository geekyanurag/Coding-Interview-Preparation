#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head;
// Insertion at the beginning
void insert(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->next = head;
    head = temp;
}

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

Node* reverseLL(Node* head){
    Node* prev = NULL, *curr = head, *nxt = NULL;
    while(curr != NULL){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    curr = prev;
    return curr;
}

int main(){
    head = NULL;
    for(int i =1; i<=5; i++)
        insert(i);
    cout<<"Linked List without reversing"<<endl;
    print(head);
    cout<<endl;
    cout<<"Linked List after reversing"<<endl;
    Node* temp = reverseLL(head);
    print(temp);
}
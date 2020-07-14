#include<bits/stdc++.h>
using namespace std;

// Given a linked list which is already sorted based on absolute values and then we have to sort it.
// The idea is to whenever we find a node which is not in correct place then move that node to front as all the negative elements are in reverse order.
// Time - O(n), Space - O(1)
struct Node{
    int data;
    Node* next;
};

void insert(Node** head, int data){
    Node* temp = new Node();
    temp->data = data;
    temp->next = *head;
    *head = temp;
}

void AbsSortList(Node** head){
    Node* prev = *head, *curr = (*head)->next;

    while(curr != NULL){
        if(curr->data < prev->data){
            prev->next = curr->next;
            curr->next = *head;
            *head = curr;
            curr = prev;
        }
        else 
            prev = curr;
        
        curr = curr->next;
    }
}

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    Node* head = NULL;
    insert(&head, -5);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, -2);
    insert(&head, 1);
    insert(&head, 0);
    cout<<"Before Sorting"<<endl;
    print(head);
    cout<<endl;
    AbsSortList(&head);
    cout<<"After Sorting"<<endl;
    print(head);
    return 0;
}
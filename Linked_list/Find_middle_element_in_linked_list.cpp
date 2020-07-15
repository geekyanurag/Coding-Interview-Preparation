#include<bits/stdc++.h>
using namespace std;

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

// Using the slow and fast pointer approach if the fast reaches the end, the slow pointer will reach to the middle because the fast pointer
// moves twice as fast as slow pointer.
void findMiddle(Node* head){
    Node* slow = head, *fast = head;

    if(head != NULL){
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        cout<<"The middle of linked list is "<<slow->data<<endl;
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
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    insert(&head, 6);
    insert(&head, 7);
    findMiddle(head);
    //print(head);
    return 0;
}
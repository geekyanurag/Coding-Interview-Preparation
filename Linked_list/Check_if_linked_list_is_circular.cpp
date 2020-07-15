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
// This is the method of using slow and fast pointers. If they meet then the list is circular.
bool isCircular(Node* head){
    if(head == NULL)
        return true;
    Node* slow = head, *fast = head;

    while(fast!= NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            return true;
    }
    return false;
}

// This is the general idea of traversing the list if the last term is pointing the head then it is circular else not.
bool isCircular1(Node* head){
    Node* temp = head;
    if(temp == NULL) return true;

    while(temp != NULL && temp->next != head)
        temp = temp->next;
    
    return (temp == head);
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
    head->next->next->next = head; // For making the list circular.
    if(isCircular(head))
        cout<<"Yes"<<endl;
    else 
        cout<<"No"<<endl;
    return 0;
}
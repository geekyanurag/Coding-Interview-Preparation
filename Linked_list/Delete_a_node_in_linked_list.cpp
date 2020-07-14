#include<bits/stdc++.h>
using namespace std;

// Deleting a node in a linked list if a key is given.
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

void deleteNode(Node** head, int key){
    Node* temp = *head, *prev;
    if(temp != NULL && temp->data == key){
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
        return;
    
    prev->next = temp->next;
    free(temp);

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
    insert(&head, 3); // Passing reference when we have to modify in the given linked list.
    insert(&head, 4);
    insert(&head, 5);
    deleteNode(&head, 4);
    print(head);  // Here we are not passing address as we only have to print we don't have to change anything in linked list.
    return 0;
}
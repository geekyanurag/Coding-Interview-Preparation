#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

// Merge Sort is done using two methods first split the list from middle. We used slow and fast pointer method to find the middle node then
// return the pointer of the front node and back node and make next of middle node as null. Then use the merging process of linked list then store the result in a new variable (result).

void split(Node* , Node**, Node**);
Node* sortedMerge(Node* , Node* );

void mergeSort(Node** head){
    Node* newHead = *head;
    Node* a, *b;

    if(newHead == NULL || newHead->next == NULL)
        return;
    
    split(newHead, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *head = sortedMerge(a, b);
}

void split(Node* head, Node** front, Node** back){
    Node* slow = head, *fast = head->next;  // Don't start both slow and fast from head.

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = head;
    *back = slow->next;
    slow->next = NULL;
}

Node* sortedMerge(Node* a, Node* b){
    Node* result = NULL;
    
    if(a == NULL)
        return b;
    else if(b == NULL)
        return a;
    
    if(a->data <= b->data){
        result = a;
        result->next = sortedMerge(a->next, b);
    }
    else{
        result = b;
        result->next = sortedMerge(a, b->next);
    }
    return result;
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
    Node* head = NULL;
    insert(&head, 1);
    insert(&head, 5);
    insert(&head, 3);
    insert(&head, 2);
    mergeSort(&head);
    print(head);
    return 0;
}
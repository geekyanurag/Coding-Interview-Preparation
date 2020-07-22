#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

// Rotation of linked list. Count till k nodes then go the last node then point that to first node then set kth node to head then set kth node's next pointer to NULL.
int countNodes(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp){
        count++;
        temp = temp->next;
    }
    return count;
}

void rotate(Node** head, int k){
    Node* curr = *head;
    int node_count = countNodes(curr);
    int count = k % node_count;  // If k is larger than the given list size.
    int cnt = 1;

    while(cnt < count && curr != NULL){
        curr = curr->next;
        cnt++;
    }
    
    if(curr == NULL)
        return;
    
    Node* kthNode = curr;
    while(curr->next != NULL)
        curr = curr->next;

    curr->next = *head;
    *head = kthNode->next;
    kthNode->next = NULL;
    
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
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    insert(&head, 7);
    insert(&head, 9);
    insert(&head, 10);
    cout<<"List before rotation"<<endl;
    print(head);
    rotate(&head, 3);
    cout<<endl;
    cout<<"List after rotation"<<endl;
    print(head);
    return 0;
}
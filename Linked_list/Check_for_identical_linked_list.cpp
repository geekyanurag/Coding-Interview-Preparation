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

// Iterative Solution
bool isIdentical(Node* a, Node* b){
    while(a && b){
        if(a->data != b->data)
            return false;
        a = a->next;
        b = b->next;
    }

    return (a == NULL && b == NULL);
}

// Recursive Solution
bool isIdenticalRecur(Node* a, Node* b){
    if(a == NULL && b == NULL)
        return true;
    if(a == NULL || b == NULL)
        return false;
    
    return (a->data == b->data && isIdenticalRecur(a->next, b->next));
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
    insert(&head1, 3);
    insert(&head1, 4);
    insert(&head1, 5);
    insert(&head2, 3);
    insert(&head2, 4);
    insert(&head2, 5);
    if(isIdentical(head1, head2))
        cout<<"Yes"<<endl;
    else 
        cout<<"No"<<endl;
    //print(head);
    return 0;
}
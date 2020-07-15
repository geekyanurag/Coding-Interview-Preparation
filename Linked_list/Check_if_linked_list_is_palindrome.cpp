#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

void reverseList(Node**);
bool compare(Node*, Node* );

bool checkPalindrome(Node* head){
    Node* slow = head, *fast = head, *prev_slow = head, *midNode = NULL, *secondHalf;
    bool res = true;

    if(head != NULL && head->next != NULL){

        while(fast && fast->next){
            prev_slow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if(fast != NULL){
            midNode = slow;
            slow = slow->next;
        }
        secondHalf = slow;
        prev_slow->next = NULL;
        reverseList(&secondHalf);
        res = compare(head, secondHalf);

        reverseList(&secondHalf);
        if(midNode != NULL){
            midNode->next = secondHalf;
            prev_slow->next = midNode;
        }
        else 
            prev_slow->next = secondHalf;
    }
    return res;
}

void reverseList(Node** head){
    Node* prev = NULL, *curr = *head, *next;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

bool compare(Node* a, Node* b){
    if(a == NULL && b == NULL)
        return true;
    
    while(a && b){
        if(a->data != b->data)
            return false;
        a = a->next;
        b = b->next;
    }
    return (a == NULL && b == NULL);
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
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);
    if(checkPalindrome(head))
        cout<<"Yes"<<endl;
    else 
        cout<<"No"<<endl;
    //print(head);
}
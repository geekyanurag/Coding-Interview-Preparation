#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

// Time - O(m + n), Space - O(1)
// In this approach we first calculate the difference of two different list's nodes count then those have greater count then move the head forward till the distance of k(difference of counts)
// Then compare both list if the data is equal then then it will be the intersection point.
int getCount(Node*);
int getPoint(Node*, Node*, int);

int intersectionPoint(Node* head1 , Node* head2){
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d;
    if((c1 - c2) > 0){
        d = c1 - c2;
        return getPoint(head1, head2, d);
    }
    else {
        d = c2 - c1;
        return getPoint(head2, head1, d);
    }
}

int getPoint(Node* head1, Node* head2, int d){
    Node* temp1 = head1;
    Node* temp2 = head2;

    for(int i = 0; i<d; i++){
        if(temp1 == NULL)
            return -1;
        temp1 = temp1->next;
    }

    while(temp1 && temp2){
        if(temp1 == temp2)
            return temp1->data;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return -1;
}

int getCount(Node* head){
    Node* temp = head;
    int count = 0;

    while(temp){
        count++;
        temp = temp->next;
    }
    return count;
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
    Node* newNode; 
    Node* head1 = new Node(); 
    head1->data = 10; 
  
    Node* head2 = new Node(); 
    head2->data = 3; 
  
    newNode = new Node(); 
    newNode->data = 6; 
    head2->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 9; 
    head2->next->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 15; 
    head1->next = newNode; 
    head2->next->next->next = newNode; 
  
    newNode = new Node(); 
    newNode->data = 30; 
    head1->next->next = newNode; 
  
    head1->next->next->next = NULL;

    cout<<"The Intersection Node is "<<intersectionPoint(head1, head2);
    return 0;
}
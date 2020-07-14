#include<bits/stdc++.h>
using namespace std;

// Using Floyd's cycle finding algorithm
// Time - O(n) && Space - O(1)
struct Node{
    int data;
    Node* next;
};

Node* head;
void insert(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->next = head;
    head = temp;
}

int detectLoop(Node* head){
    Node* slow, *fast;
    slow = head, fast = head;
    while(slow && fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return 1;
        }
    }
    return 0;
}

void print(){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    head = NULL;
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    head->next->next->next->next = head;
    if(detectLoop(head))
        cout<<"Cycle Found"<<endl;
    else 
        cout<<"Cycle Not Found"<<endl;
}
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

// Using slow and fast pointer method we can find the cycle. After finding cycle we can observe that if we point the slow pointer to head
// and fast as it is after cycle detection then if we move them ahead then slow and fast will meet at the beginning of the loop. Prove is given
// in geeksforgeeks. After that change the prev of fast to null.
void detectAndRemoveLoop(Node* head){
    if(head == NULL || head->next == NULL)
        return;
    
    Node* slow = head, *fast = head;
    slow = slow->next;
    fast = fast->next->next;

    while(fast && fast->next){
        if(slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }

    if(slow == fast){
        slow = head;
        while(slow->next != fast->next){
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
    }
}

Node* insert(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void print(Node* head){
    Node* temp = head;

    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    Node* head = insert(50); 
    head->next = head; 
    head->next = insert(20); 
    head->next->next = insert(15); 
    head->next->next->next = insert(4); 
    head->next->next->next->next = insert(10); 
    head->next->next->next->next->next = insert(60); 
    // Creating loop
    head->next->next->next->next->next->next = head->next->next->next; 
    detectAndRemoveLoop(head);
    print(head);
    return 0;
}
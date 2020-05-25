// Given linked list in sorted order who have to insert the element in the sorted linked list.
Node *sortedInsert(Node* head, int x)
{
    Node* temp = head;
    if(x <= head->data){
        Node* temp2 = new Node(x);
        temp2->next = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = temp2;
        temp = temp2;
    }
    else{
        Node* prev = temp;
        while(temp->next != head){
            if(x <= temp->data){
                Node* temp2 = new Node(x);
                temp2->next = temp;
                prev->next = temp2;
                temp = head;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        if(temp->next == head){
        if(x <= temp->data){
            Node* temp2 = new Node(x);
            temp2->next = temp;
            prev->next = temp2;
            temp = head;
        }
        else {
            prev = temp;
            Node* temp2 = new Node(x);
            prev->next = temp2;
            temp2->next = head;
            temp = head;
        }
        }
    }
    return temp;
}
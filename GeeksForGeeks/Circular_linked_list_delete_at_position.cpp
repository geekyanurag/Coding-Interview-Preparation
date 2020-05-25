// Problem is to delete the node at given position in circular linked list.
Node * deleteAtPosition(Node *head,int pos)
{
    int x = 0;
    Node* temp = head, *prev = head;
    if(pos == 1){
        while(temp->next != head){
            temp = temp->next;
        }
        if(temp->next == head){
            prev = temp;
        }
        Node* temp2 = head;
        prev->next = head->next;
        head->next = NULL;
        head = prev->next;
    }
    else{
        while(temp->next != head){
            x++;
            if(x == pos){
                prev->next = temp->next;
                temp->next = NULL;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        if(temp->next == head){
            prev->next = temp->next;
            temp->next = NULL;
        }
    }
    return head;
}
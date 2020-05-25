// Given a circular linked list , divide the list into two different linked list from halves and if size of ll is odd then first circular ll will have 1 more than the second list.
void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    int count = 0, x, z = 0;
    Node* temp = head;
    while(temp->next != head){
        count++;
        temp = temp->next;
    }
    count += 1;
    if(count & 1)
        x = (count / 2) + 1;
    else
        x = (count / 2); 
    Node* temp3 = head;
    while(temp3->next != head){
        z++;
        if(z == x){
            *head2_ref = temp3->next;
            temp3->next = head;
            *head1_ref = head;
            break;
        }
        temp3 = temp3->next;
    }
    Node* temp2 = *head2_ref;
    while(temp2->next != head){
        temp2 = temp2->next;
    }
    if(temp2->next == head)
        temp2->next = *head2_ref;
    
}
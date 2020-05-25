// Problem is to delete the middle of the linked list.
Node* deleteMid(Node* head) {
    int count = 0, x = 0;
    Node* temp = head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    int y = count / 2;
    Node* temp2 = head, *prev = head;
    while(temp2 != NULL){
        if(x == y){
            prev->next = temp2->next;
            temp2->next = NULL;
            break;
        }
        x++;
        prev = temp2;
        temp2 = temp2->next;
    }
    return head;
}
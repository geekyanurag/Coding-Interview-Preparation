// Detect loop in linked list.
int detectloop(Node *head) {
    int x = 0;
    while(head != NULL){
        if(head -> data == 0){
            x = 1;
            break;
        }
        else head->data = 0;
        head = head->next;
    }
    return x;
}
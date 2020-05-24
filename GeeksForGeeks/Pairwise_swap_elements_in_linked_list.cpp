// Swap the elements in pair from starting head node to the end of the list.
Node* pairWiseSwap(struct Node* head) {
    Node* temp = head;
     while(head != NULL){
         int x = head->data;
         if(head->next == NULL)
            break;
         int y = head->next->data;
         head->data = y;
         head->next->data = x;
         if(head->next->next == NULL)
            break;
         head = head->next->next;
     }
     return temp;
}
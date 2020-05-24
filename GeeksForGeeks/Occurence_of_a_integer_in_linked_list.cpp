// count the occurence of a given character in a linked list.
int count(struct node* head, int search_for)
{
    int count = 0;
    node* temp = head;
    while(temp != NULL){
        if(temp->data == search_for)
            count++;
        temp = temp->next;
    }
    return count;
}
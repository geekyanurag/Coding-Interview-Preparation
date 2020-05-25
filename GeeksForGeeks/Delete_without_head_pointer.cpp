// Problem is to delete the node whose reference is given and head pointer is not given.
// Idea is to copy the data of the next node and when reaches the last node then prev node next will be null.
void deleteNode(Node *node)
{
   Node* nxt = node->next, *curr = node;
   while(nxt != NULL){
       node->data = nxt->data;
       nxt = nxt->next;
       curr = node;
       node = node->next;
   }
   curr->next = NULL;
}
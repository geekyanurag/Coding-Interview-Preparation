// Problem is to reverse the linked list and return the head node.
Node* reverseList(Node *head)
{
  Node* prev = NULL, *curr = head, *nxt = NULL;
  while(curr != NULL){
      nxt = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nxt;
  }
  curr = prev;
  return curr;
}
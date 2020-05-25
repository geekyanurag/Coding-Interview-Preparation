// Problem is to add two linked list.
Node* addTwoLists(Node* first, Node* second) {
    Node* temp2 = new Node(0);
    Node* temp = temp2;
    int carry = 0;
    while(first != NULL || second != NULL){
        int first_data = (first == NULL) ? 0 : first->data;
        int second_data = (second == NULL) ? 0 : second->data;
        int sum = first_data + second_data + carry;
        int num = sum % 10;
        carry = sum / 10;
        temp->next = new Node(num);
        temp = temp->next;
        if(first != NULL)
            first = first -> next;
        if(second != NULL)
            second = second -> next;
    }
    if(carry > 0)
        temp->next = new Node(carry);
    return temp2->next;
}
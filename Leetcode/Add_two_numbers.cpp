/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Given two singly linked list and we have to add the list. l1 = 2->4->5 and l2 = 8->6->1 so ans = 0->1->7
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode(0);
        ListNode* x = l1;
        ListNode* y = l2;
        ListNode* curr = temp;
        int carry = 0, sum;
        while(x != NULL || y!= NULL){
            int a = (x != NULL) ? x->val : 0;
            int b = (y != NULL) ? y->val : 0;
            sum = a + b + carry;
            carry = sum / 10;
            sum = sum % 10;
            curr->next = new ListNode(sum);
            curr = curr->next;
            if(x != NULL)
                x = x->next;
            if(y != NULL)
                y = y->next;
        }
        if(carry > 0)
            curr->next = new ListNode(carry);
        return temp->next;
    }
};
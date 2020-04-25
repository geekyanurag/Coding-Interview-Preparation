/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        vector<int>v;
        int res = 0;
        while(temp != NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }
        int x = v.size() - 1;
        for(auto i : v){
            res += pow(2, x) * i;
            x--;
        }
        return res;
    }
};
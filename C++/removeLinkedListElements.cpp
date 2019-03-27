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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* cur = head;
        ListNode* prev = head;
        while (cur!=NULL){
            if (cur->val == val){
                if (cur==head){
                    head = head->next;
                    prev = head;
                    cur = head;
                }else{
                    prev->next = cur->next;
                    cur = cur->next;
                }
            }else{
                prev = cur;
                cur=cur->next;   
            }
        }
        return head;
    }
};
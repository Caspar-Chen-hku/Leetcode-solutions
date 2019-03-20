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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==NULL || head->next==NULL) return head;
        ListNode* prev = head;
        ListNode* cur = head->next;
        while (cur!=NULL){
            if (cur->val == prev->val){
                cur = cur->next;
                prev->next=cur;
            }else{
                prev=cur; cur=cur->next;
            }
        }
        return head;        
    }
};
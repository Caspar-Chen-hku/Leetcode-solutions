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
 
    ListNode* detectCycle(ListNode *head) {
        if (head==NULL || head->next==NULL) return NULL;
        ListNode* cur = head->next;
        ListNode* future = cur->next;
        while(future!=NULL && future->next!=NULL && cur!=future){
            cur=cur->next;
            future=future->next->next;
        }
        if (cur!=future){
            return NULL;
        }
        cur = head;
        while(cur!=future){
            cur=cur->next;
            future=future->next;
        }
        return cur;
    }
};
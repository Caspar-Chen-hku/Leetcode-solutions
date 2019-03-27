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
    ListNode* reverseList(ListNode* head) {
        if (head==NULL||head->next==NULL) return head;
        ListNode* prev= head;
        ListNode* cur = head->next;
        ListNode* future = cur->next;
        prev ->next = NULL;
        while (future!=NULL){
            cur->next=prev;
            prev=cur;
            cur=future;
            future=future->next;
        }
        cur->next=prev;
        return cur;
    }
};
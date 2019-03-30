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
    ListNode* oddEvenList(ListNode* head) {
        if (head==NULL||head->next==NULL) return head;
        ListNode* cur = head;
        ListNode* future = head->next;
        ListNode* sndhead = future;
        while (future!=NULL){
            cur->next=future->next;
            if (future->next!=NULL){
                future->next = future->next->next; 
                cur=cur->next; 
            }
            future=future->next;
        }
        cur->next = sndhead;
        return head;
    }
};
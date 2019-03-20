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
    ListNode* partition(ListNode* head, int x) {
        if (head==NULL||head->next==NULL) return head;
        ListNode* h1 = NULL;
        ListNode* h2 = NULL;
        ListNode* t1 = NULL;
        ListNode* t2 = NULL;
        ListNode* cur = head;
        while (cur!=NULL){
            if (cur->val < x){
                if (t1==NULL){
                    h1=cur; t1=cur;
                }else{
                    t1->next=cur;
                    t1=t1->next;
                }
            }else{
                if (t2==NULL){
                    h2=cur; t2=cur;
                }else{
                    t2->next=cur;
                    t2=t2->next;
                }                
            }
            cur=cur->next;
        }
        if (h1==NULL){
            h1=h2;
        }else{
            t1->next=h2;
        }
        if (t2!=NULL){
            t2->next=NULL;
        }
        return h1;
    }
};
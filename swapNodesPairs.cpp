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
    ListNode* swapPairs(ListNode* head) {
        if (head==NULL||head->next==NULL){
            return head;
        }
            
        ListNode* p = head;
        ListNode* c1 = head;
        ListNode* c2 = head->next;
        c1->next=c2->next;
        c2->next=c1;
        p = c2;
        head = c2;
        
        while(c1->next!=NULL && c1->next->next!=NULL){
            p = c1;
            c1 = c1->next;
            c2 = c1->next;
            p->next = c2;
            c1->next=c2->next;
            c2->next=c1;
        }
        
        return head;
        
    }
};
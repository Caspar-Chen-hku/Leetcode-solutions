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
    void reorderList(ListNode* head) {
        if (head==NULL||head->next==NULL) return;
        ListNode* cur = head;
        ListNode* prev = head;
        ListNode* tail =  head->next;
        while(tail->next!=NULL){
            prev = tail;
            tail = tail->next;
        }
        prev->next=NULL;
        prev = head->next;
        head->next=tail;
        tail->next=prev;
        reorderList(prev);
    }
};
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
        set<int> dup;
        while (cur!=NULL){
            if (cur->val == prev->val){
                dup.insert(cur->val);
                cur = cur->next;
                prev->next=cur;
            }else{
                prev=cur; cur=cur->next;
            }
        }
        cur=head; prev=head;
        while (cur!=NULL){
            if (dup.find(cur->val)!=dup.end()){
                if (cur==head){
                    head=cur->next;
                    cur=head; prev=head;
                }else{
                    cur=cur->next;
                    prev->next=cur;
                }
            }else{
                prev=cur;
                cur=cur->next;
            }
        }
        return head;
    }
};
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
    ListNode* insertionSortList(ListNode* head) {
        if (head==NULL||head->next==NULL) return head;
        ListNode* curtail=head;
        ListNode* cur=head;
        ListNode* todo = head->next;
        while(todo!=NULL){
            cur=head;
            curtail->next=todo->next;
            if (todo->val < head->val){
                todo->next=head;
                head=todo;
            }else{
                while(cur->val <= todo->val && 
                      cur!=curtail &&
                      cur->next!=NULL && 
                      cur->next->val <= todo->val){
                    cur=cur->next;
                }
                todo->next = cur->next;
                cur->next=todo;
                if (todo==curtail->next){
                    curtail=todo;
                }
            }
            todo = curtail->next;
            
        }
        return head;
    }
};
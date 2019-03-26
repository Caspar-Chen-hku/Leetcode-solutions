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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int num = numNodes(head)-n;
        ListNode* current = head;
        if (num==0){
            head=head->next;
        }else{
            while(num>1){
                current=current->next;
                num--;
            }
            current->next = current->next->next;
        }
        return head;
    }
    
    int numNodes(ListNode* head){
        ListNode* current = head;
        int count = 0;
        while (current!=NULL){
            count++;
            current = current->next;
        }
        return count;
    }
};
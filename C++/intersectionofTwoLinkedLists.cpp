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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        if (a==NULL || b==NULL) return NULL;
        bool changedA = false, changedB = false;
        while (a!=b){
            if (a->next==NULL){
                if (!changedA){
                    a = headB;
                    changedA = true;                   
                }else{
                    break;
                }
            }else{
                a = a->next;   
            }
            if (b->next==NULL){
                if (!changedB){
                    b = headA;
                    changedB = true;                
                }else{
                    break;
                }
            }else{
                b = b->next;
            }
        }
        if (a==b){
            return a;
        }else{
            return NULL;
        }
    }
};
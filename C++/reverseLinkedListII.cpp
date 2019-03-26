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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int count = 1;
        ListNode* priorm;
        ListNode* justm;
        ListNode* prev = head;
        ListNode* cur = head;
        ListNode* future = cur->next;
        while (count<=m-1){
            prev = cur;
            cur = future;
            future = future->next;
            count++;
        }
        priorm = prev;
        justm = cur;
        while (count<n){
            prev = cur;
            cur=future;
            future=future->next;
            cur->next = prev;
            count++;
        }
        priorm -> next = cur;
        justm -> next = future;
        if (priorm==justm) return cur;
        return head;
    }
};
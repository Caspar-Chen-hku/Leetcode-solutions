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
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> vals;
        vector<int> sum = {0};
        ListNode* cur = head;
        while (cur){
            vals.push_back(cur->val);
            cur = cur->next;
        }
        sum.push_back(vals[0]);
        for (int i=1; i<vals.size(); i++){
            sum.push_back(sum[i]+vals[i]);
        }
        ListNode* nhead = new ListNode(0);
        ListNode* ntail = nhead;
        int i = 0;
        while (i < vals.size()){
            for (int j=vals.size(); j>=i; j--){
                if (i==j){
                    ListNode* nnode = new ListNode(vals[i]);
                    ntail->next = nnode;
                    ntail = nnode;
                    i++; break;
                }else if (sum[i]==sum[j]){
                    i = j; break;
                }
            }
        }
        return nhead->next;
    }
};
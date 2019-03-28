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
    bool isPalindrome(ListNode* head) {
        vector<int> res;
        ListNode* cur = head;
        while (cur!=NULL){
            res.push_back(cur->val);
            cur=cur->next;
        }
        int l = res.size();
        for (int i=0; i<l/2; i++){
            if (res[i]!=res[l-1-i]) return false;
        }
        return true;
    }
};
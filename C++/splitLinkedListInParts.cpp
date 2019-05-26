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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res;
        int num = numNodes(root);
        int ave = num / k, more = num % k, temp;
        ListNode* cur = root;
        ListNode* prev;
        while (k>0){
            res.push_back(cur);
            temp = ave + (more > 0 ? 1 : 0);
            if (temp==0){
                k--; more--;
                continue;
            }
            while (temp>1){
                cur=cur->next; temp--;
            }
            prev = cur->next;
            cur->next = NULL;
            cur = prev;
            more--; k--;
        }
        return res;
    }
    
    int numNodes(ListNode* root){
        int ans = 0;
        ListNode* cur = root;
        while (cur){
            ans++;
            cur=cur->next;
        }
        return ans;
    }
};
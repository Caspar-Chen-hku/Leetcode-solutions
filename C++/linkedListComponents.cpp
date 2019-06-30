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
    int numComponents(ListNode* head, vector<int>& G) {
        bool exist = false; int count = 0;
        ListNode* cur = head;
        set<int> g(G.begin(), G.end());
        while (true){
            if (!cur){
                if (exist) count++;
                break;
            }else if (g.find(cur->val)==g.end()){
                if (exist) count++;
                exist = false;
            }else{
                exist = true;
            }
            cur = cur->next;
        }
        return count;
    }
};
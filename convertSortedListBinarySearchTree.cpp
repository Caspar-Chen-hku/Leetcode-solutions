/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return bst(head,NULL);
    }
    
    TreeNode* bst(ListNode* head, ListNode* end){
        if (head==end) return NULL;
        ListNode* mid = findMid(head,end);
        TreeNode* root = new TreeNode(mid->val);
        root->left = bst(head,mid);
        root->right = bst(mid->next,end);
        return root;
    }
    
    ListNode* findMid(ListNode* head, ListNode* end){
        if (head==end || head->next==end) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=end&&fast->next!=end){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};
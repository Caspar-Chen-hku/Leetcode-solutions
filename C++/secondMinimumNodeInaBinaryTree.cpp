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
    int findSecondMinimumValue(TreeNode* root) {
        long MIN=LONG_MAX, SMIN=LONG_MAX;
        f(root,MIN,SMIN);
        return SMIN==LONG_MAX?-1:SMIN;
    }
private:
    void f(TreeNode*root,long&MIN,long&SMIN){
        if(!root)   return;
        if(root->val<MIN)   SMIN=MIN,MIN=root->val;
        else if(root->val<SMIN&&root->val!=MIN) SMIN=root->val;
        f(root->left,MIN,SMIN);
        f(root->right,MIN,SMIN);
    }
};
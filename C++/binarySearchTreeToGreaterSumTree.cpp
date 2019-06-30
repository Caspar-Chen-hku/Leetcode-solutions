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
    TreeNode* bstToGst(TreeNode* root) {
        int sum;
        return change(root, 0, sum);
    }
    
    TreeNode* change(TreeNode* root, int add, int& sum){
        if (!root){
            sum = 0; return NULL;
        }
        int s1, s2;
        root->right = change(root->right, add, s2);
        root->left = change(root->left, s2+add+root->val, s1);
        sum = s1 + s2 + root->val;
        root->val = root->val + s2 + add;
        return root;
    }
};
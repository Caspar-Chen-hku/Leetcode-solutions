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
    TreeNode* pruneTree(TreeNode* root) {
        bool contain;
        return prune(root, contain);
    }
    
    TreeNode* prune(TreeNode* root, bool& contain){
        if (!root){
            contain = false; return NULL;
        }
        bool c1, c2;
        root->left = prune(root->left, c1);
        if (!c1) root->left = NULL;
        root->right = prune(root->right, c2);
        if (!c2) root->right = NULL;
        contain = c1 || c2 || root->val==1;
        return root;
    }
};
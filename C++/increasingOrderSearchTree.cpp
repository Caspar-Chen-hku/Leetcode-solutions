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
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* l = increasingBST(root->left);
        root->left = NULL;
        root->right = increasingBST(root->right);
        TreeNode* tail = l;
        while (tail && tail->right){
            tail = tail->right;
        }
        if (!tail) l=root;
        else tail->right = root;
        return l;
    }
};
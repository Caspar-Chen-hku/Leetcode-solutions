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
    TreeNode* convertBST(TreeNode* root) {
        convert(root, 0);
        return root;
    }
    
    int convert(TreeNode* root, int toAdd){
        if (!root) return toAdd;
        int r = convert(root->right, toAdd);
        root->val = root->val + r;
        return convert(root->left, root->val);
    }
};
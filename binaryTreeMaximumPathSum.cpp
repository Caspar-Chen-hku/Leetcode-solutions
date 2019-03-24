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
    
    Solution () : max_wpath(INT_MIN) {}
    
    int maxPathSum(TreeNode* root) {
        int max_spath_left = dfs(root->left);
        int max_spath_right = dfs(root->right);
        int max_wpath_turning_here = root->val + max(max_spath_left, 0)
            + max(max_spath_right, 0);
        max_wpath = max(max_wpath, max_wpath_turning_here);
        return max_wpath;
    }
    
private:
    int dfs (TreeNode* node) {
        if (!node) return 0;
        int max_spath_left = dfs(node->left);
        int max_spath_right = dfs(node->right);
        int max_spath_from_here = node->val + max(max(max_spath_left, max_spath_right), 0);
        int max_wpath_turning_here = node->val + max(max_spath_left, 0) + max(max_spath_right, 0);
        max_wpath = max(max_wpath, max_wpath_turning_here);
        return max_spath_from_here;
    } // dfs
    
    int max_wpath;
};
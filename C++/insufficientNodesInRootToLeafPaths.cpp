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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if (traverse(root, 0, limit) < limit){
            return NULL;
        }else{
            return root;
        }
    }
    
    int traverse(TreeNode* root, int prior, int limit){
        prior += root->val;
        if (!root->left && !root->right){
            return prior;
        }else if (!root->left){
            int rightsum = traverse(root->right, prior, limit);
            if (rightsum < limit) root->right = NULL;
            return rightsum;
        }else if (!root->right){
            int leftsum = traverse(root->left, prior, limit);
            if (leftsum < limit) root->left = NULL;
            return leftsum;
        }
        int leftsum = traverse(root->left, prior, limit);
        if (leftsum < limit) root->left = NULL;
        int rightsum = traverse(root->right, prior, limit);
        if (rightsum < limit) root->right = NULL;
        return max(leftsum, rightsum);
    }
};
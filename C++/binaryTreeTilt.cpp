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
    
    int sum = 0;
    
    int findTilt(TreeNode* root) {
        tilt(root);
        return sum;
    }
    
    int tilt(TreeNode* root){
        if (!root) return 0;
        int l = tilt(root->left);
        int r = tilt(root->right);
        sum += abs(l-r);
        return (l+r+root->val);
    }
};
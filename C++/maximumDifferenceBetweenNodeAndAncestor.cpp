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
    int maxAncestorDiff(TreeNode* root) {
        int minVal, maxVal;
        return maxAncestor(root, minVal, maxVal);
    }
    
    int maxAncestor(TreeNode* root, int& minVal, int& maxVal){
        if (!root->left && !root->right){
            minVal = maxVal = root->val;
            return 0;
        }else if (!root->left){
            int minRight, maxRight;
            int rightDiff = maxAncestor(root->right, minRight, maxRight);
            minVal = min(root->val, minRight);
            maxVal = max(root->val, maxRight);
            return max(rightDiff, max(abs(root->val - minRight), abs(root->val - maxRight)));
        }else if (!root->right){
            int minLeft, maxLeft;
            int leftDiff = maxAncestor(root->left, minLeft, maxLeft);
            minVal = min(root->val, minLeft);
            maxVal = max(root->val, maxLeft);
            return max(leftDiff, max(abs(root->val - minLeft), abs(root->val - maxLeft)));
        }else{
            int minRight, maxRight;
            int rightDiff = maxAncestor(root->right, minRight, maxRight);
            int rightmax = max(rightDiff, max(abs(root->val - minRight), abs(root->val - maxRight)));
            int minLeft, maxLeft;
            int leftDiff = maxAncestor(root->left, minLeft, maxLeft);
            int leftmax = max(leftDiff, max(abs(root->val - minLeft), abs(root->val - maxLeft)));
            maxVal = max(root->val, max(maxLeft, maxRight));
            minVal = min(root->val, min(minLeft, minRight));
            return max(rightmax, leftmax);
        } 
    }
};
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
    int sumRootToLeaf(TreeNode* root) {
        int cur = 0, sum = 0;
        track(root, cur, sum);
        return sum;
    }
    
    void track(TreeNode* root, int& cur, int& sum){
        int temp = cur;
        cur = 2*cur + root->val;
        if (!root->left && !root->right){
            sum += cur;
        }
        if (root->left){
            track(root->left, cur, sum);
        }
        if (root->right){
            track(root->right, cur, sum);
        }
        cur = temp;
    }
};
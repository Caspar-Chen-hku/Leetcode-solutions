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
    int pathSum(TreeNode* root, int sum) {
        int total = 0;
        path(root,sum,0,total);
        if (root){
            total += pathSum(root->left, sum);
            total += pathSum(root->right, sum);
        }
        return total;
    }
    
    void path(TreeNode* root, int sum, int cursum, int& total){
        if (!root){
            return;
        }else if (cursum+root->val==sum){
            total++;
        }
        path(root->left, sum, cursum+root->val, total);
        path(root->right, sum, cursum+root->val, total);     
    }
};
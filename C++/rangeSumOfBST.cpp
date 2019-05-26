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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (!root) return 0;
        else if (root->val < L){
            return rangeSumBST(root->right, L, R);
        }else if (root->val > R){
            return rangeSumBST(root->left, L, R);
        }else{
            return rangeSumBST(root->left, L, R) + root->val + rangeSumBST(root->right, L, R);
        }
    }
};
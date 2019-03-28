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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int b1 = root->val - p->val, b2 = root->val - q->val;
        if (b1<0&&b2<0){
            return lowestCommonAncestor(root->right, p, q);
        }else if(b1>0&&b2>0){
            return lowestCommonAncestor(root->left, p, q);
        }else{
            return root;
        }
    }
};
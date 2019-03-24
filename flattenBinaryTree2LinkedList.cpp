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
    void flatten(TreeNode* root) {
        if (root==NULL) return;
        flatten(root->right);
        if(root->left==NULL) return;
        flatten(root->left);
        TreeNode* cur = root->left;
        while (cur->right!=NULL){
            cur=cur->right;
        }
        cur->right=root->right;
        root->right= root->left;
        root->left=NULL;
    }
};
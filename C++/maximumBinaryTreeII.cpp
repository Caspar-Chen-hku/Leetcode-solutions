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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if (!root){
            TreeNode* node = new TreeNode(val);
            return node;
        }else if (val > root->val){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }else{
            root->right = insertIntoMaxTree(root->right, val);
            return root;
        }
    }
};
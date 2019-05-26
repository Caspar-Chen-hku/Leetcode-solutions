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
    
    int diameterOfBinaryTree(TreeNode* root){
        if (!root) return 0;
        return diameterOfBinaryTree1(root);
    }
    
    int diameterOfBinaryTree1(TreeNode* root) {
        if (!root) return -1;
        int l = pathToBottom(root->left);
        int r = pathToBottom(root->right);
        return max(max(l+r+2, diameterOfBinaryTree1(root->left)), 
                   diameterOfBinaryTree1(root->right));  
    }
    
    int pathToBottom(TreeNode* root){
        if (!root) return -1;
        return 1 + max(pathToBottom(root->left), pathToBottom(root->right));
    }
};
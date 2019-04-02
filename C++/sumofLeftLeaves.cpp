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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root==NULL) return 0;
        else if (leaf(root->left)) return (root->left->val + sumOfLeftLeaves(root->right));
        else return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
    
    bool leaf(TreeNode* h){
        return (h!=NULL && h->left==NULL && h->right==NULL);
    }
};
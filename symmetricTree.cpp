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
    bool isSymmetric(TreeNode* root) {
        if (root==NULL) return true;
        reverse(root->left);
        return equal(root->left, root->right);
    }
    
    void reverse(TreeNode* root) {
        if (root==NULL) return;
        reverse(root->left); 
        reverse(root->right);
        TreeNode* temp = root->left;
        root->left=root->right;
        root->right = temp;
    }
    
    bool equal(TreeNode* p, TreeNode* q ){
        if (p==NULL) return q==NULL;
        else if (q==NULL) return false;
        return p->val == q->val && 
            equal(p->left,q->left) &&
            equal(p->right,q->right);
    }
}; 
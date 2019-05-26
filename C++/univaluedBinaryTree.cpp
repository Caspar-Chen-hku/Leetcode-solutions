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
    set<int> vals;
    
    bool isUnivalTree(TreeNode* root) {
        if (!root) return true;
        else{
            vals.insert(root->val);
            return isUnivalTree(root->left) &&  isUnivalTree(root->right) && vals.size()==1;
        }
    }
};
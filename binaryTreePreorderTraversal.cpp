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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root==NULL) return result;
        result.push_back(root->val);
        vector<int> l = preorderTraversal(root->left);
        result.insert(result.end(),l.begin(),l.end());
        l = preorderTraversal(root->right);
        result.insert(result.end(),l.begin(),l.end());
        return result;
    }
};
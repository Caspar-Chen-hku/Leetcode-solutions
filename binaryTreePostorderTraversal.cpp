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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root==NULL){
            return result;
        }
        vector<int> l = postorderTraversal(root->left);
        result.insert(result.end(),l.begin(),l.end());
        l = postorderTraversal(root->right);
        result.insert(result.end(),l.begin(),l.end());
        result.push_back(root->val);
        return result;
    }
};
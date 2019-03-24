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
    bool isValidBST(TreeNode* root) {
        vector<int> vals;
        return isValid(root,vals);
    }
    
    bool isValid(TreeNode* root, vector<int>& vals) {
        if (root==NULL) return true;
        bool result = isValid(root->left,vals);
        int l1 = vals.size();
        vals.push_back(root->val);
        result = result && isValid(root->right,vals);
        int l2 = vals.size();
        return result && 
            (l1==0 || vals[l1-1] < vals[l1]) && 
            (l2==l1+1 || vals[l1] < vals[l1+1]);
    }
};
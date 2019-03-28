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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> sol;
        listVals(root,sol);
        return sol[k-1];
    }
    
    void listVals(TreeNode* root, vector<int>& sol){
        if (root==NULL) return;
        listVals(root->left,sol);
        sol.push_back(root->val);
        listVals(root->right,sol);
    }
};
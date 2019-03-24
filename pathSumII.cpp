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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> sol;
        vector<int> cur;
        path(root,sum,cur,sol);
        return sol;
    }
    
    void path(TreeNode* root, int sum, vector<int>& cur, vector<vector<int>>& sol ) {
        if (root==NULL){
            return;
        }
        int v = root->val;
        if (root->left==NULL && root->right==NULL && v==sum){
            cur.push_back(v);
            sol.push_back(cur);
            cur.pop_back();
            return;
        }
        cur.push_back(v);
        path(root->left,sum-v,cur,sol);
        path(root->right,sum-v,cur,sol);
        cur.pop_back();
    }
};
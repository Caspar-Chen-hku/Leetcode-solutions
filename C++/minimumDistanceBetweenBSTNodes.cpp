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
    
    vector<int> vals;
    
    int minDiffInBST(TreeNode* root) {
        buildTree(root);
        int minDiff = INT_MAX;
        for (int i=0; i<vals.size()-1; i++){
            minDiff = min(minDiff, vals[i+1]-vals[i]);
        }
        return minDiff;
    }
    
    void buildTree(TreeNode* root){
        if (!root) return;
        buildTree(root->left);
        vals.push_back(root->val);
        buildTree(root->right);
    }
};
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
    int minDiff = INT_MAX;
    vector<int> vals;
    
    int getMinimumDifference(TreeNode* root) {
        getMin(root);
        return minDiff;
    }
    
    void getMin(TreeNode* root){
        if (root==NULL) return;
        getMin(root->left);
        int temp;
        if (!vals.empty()){
            minDiff = min(minDiff,abs(vals.back()-root->val));
        }
        vals.push_back(root->val);
        temp = vals.size(); getMin(root->right);
        if (vals.size()>temp){
            minDiff = min(minDiff,abs(vals[temp]-root->val));
        }
    }
};
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
    vector<vector<string>> t;
    
    vector<vector<string>> printTree(TreeNode* root) {
        int m = height(root), n = pow(2,m)-1;
        t = vector<vector<string>>(m, vector<string>(n, ""));
        construct(root, 0, n-1, 0);
        return t;
    }
    
    void construct(TreeNode* root, int s, int e, int row ){
        if (!root) return;
        int mid = (s+e)/2;
        t[row][mid] = to_string(root->val);
        construct(root->left, s, mid-1, row+1);
        construct(root->right, mid+1, e, row+1);
    }
    
    int height(TreeNode* root){
        if (!root) return 0;
        return max(height(root->left),height(root->right))+1;
    }
};
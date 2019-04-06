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
    map<int,int> m;
    int maxCount = 0;
    
    vector<int> findMode(TreeNode* root) {
        mode(root); vector<int> res;
        for (auto e:m){
            if (e.second==maxCount){
                res.push_back(e.first);
            }
        }
        return res;
    }
    
    void mode(TreeNode* root){
        if (!root) return;
        maxCount = max( maxCount, ++m[root->val]);
        mode(root->left); mode(root->right);
    }
};
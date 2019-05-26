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
    
    vector<int> t;
    
    bool findTarget(TreeNode* root, int k) {
        serialize(root);
        int i=0, j=t.size()-1;
        while (i<j){
            if (t[i]+t[j]==k) return true;
            else if (t[i]+t[j]>k) j--;
            else i++;
        }
        return false;
    }
    
    void serialize(TreeNode* root){
        if (!root) return;
        serialize(root->left);
        t.push_back(root->val);
        serialize(root->right);
    }
};
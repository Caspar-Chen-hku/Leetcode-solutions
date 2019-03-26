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
    bool isBalanced(TreeNode* root) {
        int height;
        return balanced(root,height);
    }
    
    bool balanced(TreeNode* root, int& height){
        if (root==NULL){
            height = 0; return true;
        }
        int h1,h2;
        bool result = balanced(root->left,h1) && balanced(root->right,h2);
        height = (h1>h2?h1:h2) + 1;
        return result && abs(h1-h2)<2;
    }
};
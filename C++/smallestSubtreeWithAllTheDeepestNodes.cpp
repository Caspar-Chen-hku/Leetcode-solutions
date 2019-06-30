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
    // return {leftheight, rightheight}
    pair<int,int> getHeight(TreeNode* node)
    {
        if (!node) return {0,0};
        
        auto left = getHeight(node->left);
        auto right = getHeight(node->right);
        return make_pair(1+max(left.first, left.second),
                         1+max(right.first,right.second));
    }
    
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root) return root;
        
        auto p = getHeight(root);

        if (p.first > p.second) return subtreeWithAllDeepest(root->left);
        if (p.first < p.second) return subtreeWithAllDeepest(root->right);
        return root;
    }
};
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        else return pathThru(root);
    }
    
    //pair<len, val>
    int pathThru(TreeNode* root){
        if (!root) return -1;
        int res = 0;
        if (root->left && root->left->val == root->val){
            res += 1+path(root->left);
        }
        if (root->right && root->right->val == root->val){
            res += 1+path(root->right);
        }
        return max(res, max(pathThru(root->left), pathThru(root->right)));
    }
    
    int path(TreeNode* root){
        if (!root) return -1;
        int res = 0;
        if (root->left && root->left->val == root->val){
            res = max(res, 1+path(root->left));
        }
        if (root->right && root->right->val == root->val){
            res = max(res, 1+path(root->right));
        }
        return res;
    }
};
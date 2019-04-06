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
    int findBottomLeftValue(TreeNode* root) {
        int depth;
        return leftMost(root,depth);
    }
    
    int leftMost(TreeNode* root, int& depth){
        if (root==NULL){
            depth = 0; return -1;
        }
        int dl, dr;
        int l = leftMost(root->left, dl);
        int r = leftMost(root->right, dr);
        depth = 1 + max(dl,dr);
        if (depth==1){
            return root->val;
        }else if (depth==1+dl){
            return l;
        }else{
            return r;
        }
    }
};
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
    vector<TreeNode*> allPossibleFBT(int N) {
        if (N%2==0) return {};
        else if (N<0) return {NULL};
        else if (N==1){
            return {new TreeNode(0)};
        }
        vector<TreeNode*> res;
        for (int i=1; i<N; i+=2){
            vector<TreeNode*> l = allPossibleFBT(i);
            vector<TreeNode*> r = allPossibleFBT(N-1-i);
            for (TreeNode* lnode:l){
                for (TreeNode* rnode:r){
                    TreeNode* root = new TreeNode(0);
                    root->left = lnode;
                    root->right = rnode;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
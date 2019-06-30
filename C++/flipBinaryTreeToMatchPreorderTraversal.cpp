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
    
    vector<int> flips;
    int ind = 0;
    bool impossible = false;
    https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/discuss/
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        flip(root, voyage);
        if (impossible){
            return {-1};
        }else{
            return flips;
        }
    }
    
    void flip(TreeNode* root, vector<int>& voyage){
        if (!root) return;
        else if (root->val != voyage[ind]){
            impossible = true; return;
        }else{
            ind++;
            if (root->left && voyage[ind]!=root->left->val){
                flips.push_back(root->val);
                flip(root->right, voyage);
                flip(root->left, voyage);
            }else{
                flip(root->left, voyage);
                flip(root->right, voyage);
            }
        }
    }
};
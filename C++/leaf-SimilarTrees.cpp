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
    
    vector<int> l1;
    vector<int> l2;
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        leaf1(root1);
        leaf2(root2);
        return l1==l2;
    }
    
    void leaf1(TreeNode* root){
        if (!root) return;
        else if (!root->left && !root->right){
            l1.push_back(root->val);
        }else{
            leaf1(root->left);
            leaf1(root->right);
        }
    }
    
     void leaf2(TreeNode* root){
        if (!root) return;
        else if (!root->left && !root->right){
            l2.push_back(root->val);
        }else{
            leaf2(root->left);
            leaf2(root->right);
        }
    }   
};
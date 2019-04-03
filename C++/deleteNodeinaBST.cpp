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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        else if (root->val > key){
            root->left = deleteNode(root->left, key);
        }else if (root->val < key){
            root->right = deleteNode(root->right, key);
        }else{
            if (!root->left && !root->right){
                return NULL;
            }else if (!root->left){
                return root->right;
            }else if (!root->right){
                return root->left;
            }else{
                TreeNode* parent = root;
                TreeNode* cur = root->right;
                while (cur->left){
                    parent = cur;
                    cur = cur->left;
                }
                root->val = cur->val;
                if (parent==root){
                    root->right = cur->right;
                }else{
                    parent->left = deleteNode(cur,cur->val);
                }
            }
        }
        return root;
    }
};
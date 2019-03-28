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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int t1 = find(root,p), t2 = find(root,q);
        if (t1==-1&&t2==-1){
            return lowestCommonAncestor(root->left,p,q);
        }else if (t1==1&&t2==1){
            return lowestCommonAncestor(root->right,p,q);
        }else{
            return root;
        }
    }
    
    int find(TreeNode* root, TreeNode* p){
        if (root==p) return 0;
        else if (root==NULL) return -2;
        else if (find(root->left,p)!=-2) return -1;
        else if (find(root->right,p)!=-2) return 1;
        else return -2;
    }
};
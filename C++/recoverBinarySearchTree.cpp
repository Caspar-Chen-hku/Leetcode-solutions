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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> sol;
        getList(root, sol);
        bool exist = false;
        int l = sol.size();
        int first,second;
        for (int i=0; i<l; i++){
            if ((i>0 && sol[i]->val < sol[i-1]->val) ||
                (i<l-1 && sol[i]->val > sol[i+1]->val)){
                if (!exist){
                    first = i; exist=true;
                }else{
                    second = i;
                }
            }
        }
        int temp = sol[first]->val;
        sol[first]->val = sol[second]->val;
        sol[second]->val = temp;
    }
    
    void getList(TreeNode* root, vector<TreeNode*>& sol){
        if (root==NULL) return;
        getList(root->left,sol);
        sol.push_back(root);
        getList(root->right,sol);
    }
};
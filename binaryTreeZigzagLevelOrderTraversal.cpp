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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> cur;
        vector<vector<int>> sol;
        if (root==NULL) return sol;
        cur.push(root);
        getSol(cur,sol,false);
        return sol;
    }
    
    void getSol(stack<TreeNode*> cur, vector<vector<int>>& sol, bool right){
        stack<TreeNode*> next;
        vector<int> term;
        TreeNode* temp;
        while(!cur.empty()) {
            temp = cur.top();
            term.push_back(temp->val);
            if (!right){
                if (temp->left != NULL) next.push(temp->left);
                if (temp->right != NULL) next.push(temp->right);
            }else{
                if (temp->right != NULL) next.push(temp->right);
                if (temp->left != NULL) next.push(temp->left);
            }
            cur.pop();
        }
        sol.push_back(term);
        if (next.empty()) return;
        else getSol(next,sol,!right);
    }
};
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> cur;
        vector<vector<int>> sol;
        if (root==NULL) return sol;
        cur.push(root);
        getSol(cur,sol);
        return sol;
    }
    
    void getSol(queue<TreeNode*> cur, vector<vector<int>>& sol){
        queue<TreeNode*> next;
        vector<int> term;
        TreeNode* temp;
        while(!cur.empty()) {
            temp = cur.front();
            term.push_back(temp->val);
            if (temp->left != NULL) next.push(temp->left);
            if (temp->right != NULL) next.push(temp->right);
            cur.pop();
        }
        sol.push_back(term);
        if (next.empty()) return;
        else getSol(next,sol);
    }
    
    
};
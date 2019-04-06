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
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        vector<int> res;
        q.push(root);
        int curMax;
        TreeNode* temp;
        while (!q.empty()){
            curMax = INT_MIN;
            for (int i=q.size(); i>0; i--){
                temp = q.front();
                curMax = max(curMax, temp->val);
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
                q.pop();
            }
            res.push_back(curMax);
        }
        return res;
    }
};
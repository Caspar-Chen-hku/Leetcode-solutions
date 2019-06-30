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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp;
        bool nulled = false;
        while (!q.empty()){
            for (int i=q.size(); i>0; i--){
                temp = q.front();
                q.pop();
                if (!temp->left) nulled = true;
                else{
                    q.push(temp->left);
                    if (nulled) return false;
                }
                if (!temp->right) nulled = true;
                else {
                    q.push(temp->right);
                    if (nulled) return false;                    
                }
            }
        }
        return true;
    }
};
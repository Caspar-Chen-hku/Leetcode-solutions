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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        else if (!root->left&&!root->right) return 1;
        else if (!root->left) return widthOfBinaryTree(root->right);
        else if (!root->right) return widthOfBinaryTree(root->left);
        map<TreeNode*, int> d;
        queue<TreeNode*> q;
        q.push(root);
        d[root] = 0;
        int curdiff = 0, curmin, curmax;
        while (!q.empty()){
            curmin = INT_MAX; curmax = 0;
            for (int i=q.size(); i>0; i--){
                TreeNode* temp = q.front();
                q.pop();
                curmin = min(curmin, d[temp]);
                curmax = max(curmax, d[temp]);
                if (temp->left){
                    q.push(temp->left);
                    d[temp->left] = 2*d[temp];
                }
                if (temp->right){
                    q.push(temp->right);
                    d[temp->right] = 2*d[temp]+1;
                }
            }
            curdiff = max(curdiff, curmax-curmin+1);
        }
        return curdiff;
    }
};
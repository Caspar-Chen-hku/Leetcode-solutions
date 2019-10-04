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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d==1){
            TreeNode* nroot = new TreeNode(v);
            nroot->left = root;
            return nroot;
        }
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp;
        while (!q.empty()){
            d--;
            for (int i=q.size(); i>0; i--){
                temp = q.front();
                q.pop();
                if (d==1){
                    TreeNode* l = new TreeNode(v);
                    TreeNode* r = new TreeNode(v);
                    l->left = temp->left; r->right = temp->right;
                    temp->left = l; temp->right = r;
                }else{
                    if (temp->left) q.push(temp->left);
                    if (temp->right) q.push(temp->right);
                }
            }
        }
        return root;
    }
};
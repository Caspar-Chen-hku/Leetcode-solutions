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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        bool foundx = false, foundy = false;
        TreeNode* temp;
        map<int,int> parent;
        while (!q.empty()){
            for (int i=q.size(); i>0; i--){
                temp = q.front();
                if (temp->val == x) foundx = true;
                else if (temp->val == y) foundy = true;
                if (temp->left){
                    q.push(temp->left);
                    parent[temp->left->val] = temp->val;
                }
                if (temp->right){
                    q.push(temp->right);
                    parent[temp->right->val] = temp->val;
                }
                q.pop();
            }
            if (foundx && foundy && parent[x]!=parent[y]){
                return true;
            }else if (!foundx && !foundy){
                continue;
            }else{
                return false;
            }
        }
        return false;
    }
};
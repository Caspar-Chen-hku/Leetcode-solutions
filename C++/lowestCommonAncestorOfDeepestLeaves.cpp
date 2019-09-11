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
    map<TreeNode*, int> depth;
    int d;
        
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root) return NULL;
        d = findDepth(root);
        return findanc(root);
    }
    
    TreeNode* findanc(TreeNode* root){
        if (!root) return NULL;
        else if (depth[root]==d) return root;
        TreeNode* l = findanc(root->left);
        TreeNode* r = findanc(root->right);
        if (l && r){
            return root;
        }else if (l){
            return l;
        }else if (r){
            return r;
        }else{
            return NULL;
        }
    }
    
    int findDepth(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        int cur = 0;
        while (!q.empty()){
            for (int i=q.size(); i>0; i--){
                TreeNode* temp = q.front();
                depth[temp] = cur;
                q.pop();
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            cur++;
        }
        return cur-1;
    }
};
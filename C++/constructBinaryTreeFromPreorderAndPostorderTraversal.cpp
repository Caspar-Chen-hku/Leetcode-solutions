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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return construct(pre, 0, pre.size()-1, post, 0, post.size()-1);
    }
    
    TreeNode* construct(vector<int>& pre, int prei, int prej, 
                        vector<int>& post, int posti, int postj){
        if (prei>prej) return NULL;
        TreeNode* root = new TreeNode(pre[prei]);
        if (prei==prej){
            root->left = NULL; root->right = NULL;
            return root;
        } 
        int mid = 1;
        for (int i=1; i<=prej-prei; i++){
            if (pre[prei+i]==post[postj-1] && (i<2 || post[posti+i-2]==pre[prei+1])){
                mid = i; break;
            }
        }
        root->left = construct(pre, prei+1, prei+mid-1, post, posti, posti+mid-2);
        root->right = construct(pre, prei+mid, prej, post, posti+mid-1, postj-1);
        return root;
    }
};
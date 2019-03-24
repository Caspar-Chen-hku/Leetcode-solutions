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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int l1=inorder.size(), l2=postorder.size();
        if (l1==0) return NULL;
        return build(inorder,0,l1-1,postorder,0,l2-1);
    }
    
    TreeNode* build(vector<int>& inorder, int s1, int e1, vector<int>& postorder, int s2, int e2 ) {
        if (s1>e1) return NULL;
        int ind, nextsize;
        for (int i=s1; i<=e1; i++){
            if (inorder[i]==postorder[e2]){
                ind=i; break;
            }
        }
        nextsize = ind-s1;
        TreeNode* root = new TreeNode(postorder[e2]);
        root->left = build(inorder,s1,ind-1,postorder,s2,s2+nextsize-1);
        root->right = build(inorder,ind+1,e1,postorder,s2+nextsize,e2-1);
        return root;
    }
};

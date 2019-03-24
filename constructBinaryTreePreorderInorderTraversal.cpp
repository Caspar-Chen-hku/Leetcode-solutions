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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int l1=preorder.size(), l2=inorder.size();
        if (l1==0) return NULL;
        return build(preorder,0,l1-1,inorder,0,l2-1);
    }
    
    TreeNode* build(vector<int>& preorder, int s1, int e1, vector<int>& inorder, int s2, int e2 ) {
        if (s1>e1) return NULL;
        int ind, nextsize;
        for (int i=s2; i<=e2; i++){
            if (inorder[i]==preorder[s1]){
                ind=i; break;
            }
        }
        nextsize = ind-s2;
        TreeNode* root = new TreeNode(preorder[s1]);
        root->left = build(preorder,s1+1,s1+nextsize,inorder,s2,ind-1);
        root->right = build(preorder,s1+nextsize+1,e1,inorder,ind+1,e2);
        return root;
    }
};
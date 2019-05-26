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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return bst(preorder, 0, preorder.size()-1);
    }
    
    TreeNode* bst(vector<int>& preorder, int start, int end){
        if (start>end){
            return NULL;
        }else{
            TreeNode* root = new TreeNode(preorder[start]);
            int ind = find(preorder, start, end);
            root->left = bst(preorder, start+1, ind);
            root->right = bst(preorder, ind+1, end);
            return root;
        }
    }
    
    int find(vector<int>& preorder, int start, int end){
        int i=start+1, j=end, t=preorder[start], mid;
        while (i<=j){
            mid = (i+j)/2;
            if (preorder[mid]<t && (mid==end || preorder[mid+1]>t)){
                return mid;
            }else if (preorder[mid]>t){
                j = mid-1;
            }else{
                i = mid+1;
            }
        }
        return start;
    }
};
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l = nums.size();
        return bst(nums,0,l-1);
    }
    
    TreeNode* bst(vector<int>& nums, int start, int end){
        if (start>end) return NULL;
        int mid = (end+start)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = bst(nums,start,mid-1);
        root->right = bst(nums,mid+1,end);
        return root;
    }
};
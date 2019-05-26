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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return construct(nums, 0, nums.size()-1);
    }
    
    TreeNode* construct(vector<int>& nums, int s, int e) {
        if (s>e) return NULL;
        int m = nums[s], ind = s;
        for (int i=s+1; i<=e; i++){
            if (nums[i]>m){
                m = nums[i]; ind = i;
            }
        }
        TreeNode* node = new TreeNode(m);
        node->left = construct(nums, s, ind-1);
        node->right = construct(nums, ind+1, e);
        return node;
    }
};
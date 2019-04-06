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
    
    int maxCnt = 0;
    map<int,int> sumCnt;
    vector<int> res;
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        findSum(root);
        return res;
    }
    
    int findSum(TreeNode* root){
        if (!root) return 0;
        int l = findSum(root->left);
        int r = findSum(root->right);
        int sum = l+r+root->val;
        if (++sumCnt[sum] >= maxCnt){
            if (sumCnt[sum]>maxCnt) res.clear();
            res.push_back(sum);
            maxCnt = sumCnt[sum];
        }
        return sum;
    }
};
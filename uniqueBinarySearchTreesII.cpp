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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        if (n<1) return result; 
        return generate(1,n);
    }
    
    vector<TreeNode*> generate(int start, int end) {
        vector<TreeNode*> result;
        if (start>end) {
            result.push_back(NULL);
            return result;
        }else if (start==end){
            TreeNode* temp = new TreeNode(start);
            temp->left=NULL;
            temp->right=NULL;
            result.push_back(temp);
            return result;
        }
        for (int i=start; i<=end; i++){
           vector<TreeNode*> l = generate(start,i-1);
           vector<TreeNode*> r = generate(i+1,end);
            for (int j=0; j<l.size(); j++){
                for (int k=0; k<r.size(); k++){
                    TreeNode* temp = new TreeNode(i);
                    temp->left = l[j];
                    temp->right = r[k];
                    cout << temp->val << endl; 
                    result.push_back(temp);
                }
            }
        }
        return result;
    }
};
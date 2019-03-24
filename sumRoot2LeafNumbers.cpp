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
    int sumNumbers(TreeNode* root) {
        vector<vector<int>> sol;
        vector<int> cur;
        paths(root,sol,cur);
        long int temp = 0, power = 1, sum = 0;
        for (int i=0; i<sol.size(); i++){
            temp = 0; power = 1;
            for (int j=sol[i].size()-1; j>=0; j--){
                temp += sol[i][j]*power;
                power *= 10;
            }
            cout << temp << endl;
            sum += temp;
        }
        return sum;
    }
    
    void paths(TreeNode* root, vector<vector<int>>& sol, vector<int>& cur ){
        if (root==NULL){
            return;
        }else if (root->left==NULL && root->right==NULL){
            while (!cur.empty()&&cur[0]==0){
                cur.erase(cur.begin());
            }
            cur.push_back(root->val);
            sol.push_back(cur);
            cur.pop_back();
            return;
        }
        cur.push_back(root->val);
        paths(root->left,sol,cur);
        paths(root->right,sol,cur);
        if (!cur.empty()){
            cur.pop_back();         
        }  
    }
};
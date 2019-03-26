class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> sol;
        vector<int> cur;
        combineRec(n,k,sol,cur);
        return sol;
    }
    
    void combineRec(int n, int k, vector<vector<int>>& sol, vector<int>& cur){
        if (k==0||n==0){
            sol.push_back(cur);
            return;
        }
        for (int i=n; i>=k; i--){
            cur.push_back(i);
            combineRec(i-1, k-1, sol, cur);
            cur.pop_back();
        }
    }
};
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int l = A.size();
        vector<vector<int>> sol(l, vector<int>(l, 0));
        for (int i=0; i<l; i++){
            sol[l-1][i] = A[l-1][i];
        }
        for (int i=l-2; i>=0; i--){
            for (int j=0; j<l; j++){
                sol[i][j] = sol[i+1][j];
                if (j>0){
                    sol[i][j] = min(sol[i][j], sol[i+1][j-1]);
                }
                if (j<l-1){
                    sol[i][j] = min(sol[i][j], sol[i+1][j+1]);
                }
                sol[i][j] += A[i][j];
            }
        }
        int minCost = INT_MAX;
        for (int i=0; i<l; i++){
            minCost = min(minCost, sol[0][i]);
        }
        return minCost;
    }
};
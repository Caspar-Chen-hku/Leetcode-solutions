class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int dp[31][1001] = {0};
        int M = 1e9+7;
        
        int t_lim = min(target, f);
        for(int t = 1; t <= t_lim; t++) dp[1][t] = 1;
            
        for(int i = 2; i <= d; i++) dp[i][i] = 1;
        
        for(int i = 2; i <= d; i++)
        {
            int j_lim = min(i*f, target);
            for(int j = i+1; j<= j_lim; j++)
            {
                int k_lim = min(f, j-1);
                for(int k = 1; k <= k_lim; k++)
                {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % M;
                }
            }
        }
        return dp[d][target];         
    }
};
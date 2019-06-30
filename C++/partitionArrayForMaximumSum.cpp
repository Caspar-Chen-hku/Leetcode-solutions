class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();
        int* dp = new int[n];
        dp[0] = A[0];
        for(int i = 1; i < n; i++) {
            int j = i;
            int maxInPart = A[j];
            for(j = i; j > i - K && j >= 0; j--) {
                maxInPart = max(maxInPart, A[j]);
                int prev = 0;
                if(j - 1 >= 0) prev = dp[j - 1];
                dp[i] = max(dp[i], prev + maxInPart * (i - j + 1));
            }
        }
        return dp[n - 1];
    }
};
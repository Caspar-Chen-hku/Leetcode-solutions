class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        vector<bool> dp(1600, false);
        dp[0]=true;
        for (auto stone : stones)
        {
            sum += stone;
            for (int i = 1500; i - stone >= 0; i--)
            if (dp[i - stone])
                dp[i] = true;
        }
 
        for (int i = sum/2 ; i >= 0; i--)
            if (dp[i])
                return (sum - i) - i;
        return 0;    
    }
};
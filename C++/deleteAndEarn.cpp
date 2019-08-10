class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> cur = {nums[0]};
        for (int i=1; i<nums.size(); i++){
            if (nums[i]==nums[i-1]){
                cur.back() += nums[i];
            }else if (nums[i]==nums[i-1]+1){
                cur.push_back(nums[i]);
            }else{
                res.push_back(cur);
                cur = {nums[i]};
            }
        }
        res.push_back(cur);
        int* dp;
        int sol = 0;
        for (auto p:res){
            dp = new int[p.size()+1];
            dp[0] = 0; dp[1] = p[0];
            for (int i=2; i<=p.size(); i++){
                dp[i] = max(dp[i-1], dp[i-2]+p[i-1]);
            }
            sol += dp[p.size()];
            delete[] dp; 
        }
        return sol;
    }
};
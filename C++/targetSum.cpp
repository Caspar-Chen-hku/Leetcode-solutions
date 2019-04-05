class Solution {
public:
    int res = 0;
    
    int findTargetSumWays(vector<int>& nums, int S) {
        dfs(nums, S, 0);
        return res;
    }

    void dfs(vector<int>& nums, long S, int cur){
        if(cur == nums.size()){
            if(S == 0)
                res+=1;
        }else{
            dfs(nums, (long) S-nums[cur], cur+1);
            dfs(nums, (long) S+nums[cur], cur+1);
        }
    }
};
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum =0, l = nums.size();
        if (l==0) return true;
        if (nums.empty()) return true;
        for (auto e:nums){
            sum += e;
        }
        if (sum%2!=0) return false;
        int target = sum/2;
        bool** cursum = new bool*[l+1];
        for (int i=0; i<=l; i++){
            cursum[i] = new bool[target+1];
        }
        for (int i=0; i<=l; i++){
            cursum[i][0] = true;
        }
        for (int i=1; i<=target; i++){
            cursum[0][i] = false;
        }
        for (int i=1; i<=l; i++){
            for (int j=1; j<=target; j++){
                cursum[i][j] = cursum[i-1][j];
                if (!cursum[i][j] && nums[i-1]<=j){
                    cursum[i][j] = cursum[i-1][j-nums[i-1]];
                }
            }
        }
        return cursum[l][target];
    }
};
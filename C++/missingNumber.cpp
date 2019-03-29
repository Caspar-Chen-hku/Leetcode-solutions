class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = nums.size();
        int res = l*(l+1)/2;
        for (int i=0; i<l; i++){
            res -= nums[i];
        }
        return res;
    }
};
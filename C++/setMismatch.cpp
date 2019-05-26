class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int dup = 0, lost = 1;
        for (int i=1; i<nums.size(); i++){
            if(nums[i]==nums[i-1]){
                dup = nums[i];
            }else if (nums[i]>nums[i-1]+1){
                lost = nums[i-1]+1;
            }
        }
        return {dup, nums.back()==nums.size()?lost:nums.size()};
    }
};
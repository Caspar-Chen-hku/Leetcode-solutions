class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int count = 1, longest = 1;
        for (int i=1; i<nums.size(); i++){
            if (nums[i]>nums[i-1]){
                count++;
            }else{
                longest = max(longest, count);
                count = 1;
            }
        }
        return max(longest, count);
    }
};
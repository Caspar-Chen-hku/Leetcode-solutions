class Solution {
public:
    int minMoves(vector<int>& nums) {
        if (nums.empty()) return 0;
        int minVal = nums[0];
        for (int n:nums){
            minVal = min(minVal, n);
        }
        int result = 0;
        for (int n:nums){
            result += (n-minVal);
        }
        return result;
    }
};
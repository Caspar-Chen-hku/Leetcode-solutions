class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = nums.size();
        return max(nums[0]*nums[1]*nums.back(), nums[l-3]*nums[l-2]*nums.back());
    }
};
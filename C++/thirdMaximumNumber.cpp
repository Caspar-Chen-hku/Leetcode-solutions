class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = nums.size()-2;
        int count = 2;
        while (i>=0){
            if (nums[i]<nums[i+1]) count--;
            if (count==0) return nums[i];
            i--;
        }
        return nums.back();
    }
};
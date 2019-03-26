class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int l = nums.size();
        if (l==1) return nums[0];
        int result = nums[0] ^ nums[1];
        for (int i=2; i<l; i++){
            result ^= nums[i];
        }
        return result;
    }
};
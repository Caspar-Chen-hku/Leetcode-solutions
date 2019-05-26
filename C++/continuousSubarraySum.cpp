class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum; int l = nums.size();
        for (int i=0; i<l-1; i++){
            sum = nums[i];
            for (int j=i+1; j<l; j++){
                sum += nums[j];
                if (sum == k || (k!=0 && sum%k==0)) return true;
            }
        }
        return false;
    }
};
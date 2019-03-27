class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        int minarr = INT_MAX, sum = nums[0];
        int i=0, j=0;
        while (j<nums.size()){
            if (sum>=s){
                minarr = min(minarr, j-i+1);
                sum -= nums[i];
                i++; 
            }else{
                j++;
                if (j==nums.size()) break;
                sum += nums[j];
            }
        }
        if (minarr == INT_MAX){
            return 0;
        }else{
            return minarr;
        }
    }
};
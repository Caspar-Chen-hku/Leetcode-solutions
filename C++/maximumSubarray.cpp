class Solution {
public:
    
    int maxArray(vector<int>& nums){
        int result = nums[0];
        for (int i=1; i<nums.size(); i++){
            if (nums[i]>result){
                result = nums[i];
            }
        }
        return result;
    }
    
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int realsum=0;
        for (int i=0; i<nums.size(); i++){
            sum += nums[i];
            if (sum>realsum){
                realsum=sum;
            }else if (sum<0){
                sum=0;
            }
        }
        if (realsum==0){
            return maxArray(nums);
        }else{
            return realsum;
        }
    }
};
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=nums.size();
        int i=0, j=l-1, mid;
        while(i<=j){
            mid = (i+j)/2;
            if (mid==l-1 || nums[mid]>nums[mid+1]){
                break;
            }else if(nums[mid]>=nums[0]){
                i = mid+1;
            }else{
                j = mid-1;
            }
        }
        if (mid==l-1){
            return nums[0];
        }else{
            return nums[mid+1];   
        }
    }
};
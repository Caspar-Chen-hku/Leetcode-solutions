class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1,p=0;
        while(i<=j){
            p = (i+j)/2;
            if (nums[p]>=target&&(p==0||nums[p-1]<target)) return p;
            else if(nums[p]<target) i=p+1;
            else j=p-1;
        }
        return i;
    }
};
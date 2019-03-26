class Solution {
public:
    int findMin(vector<int>& nums) {
        int l =nums.size();
        int mid = findPivot(nums,0,l-1);
        if (mid==l-1){
            return nums[0];
        }else{
            return nums[mid+1];   
        }        
    }
                
    int findPivot(vector<int>& nums, int i, int j){
        int mid, l = nums.size();
        if(i<=j){
            mid = (i+j)/2;
            if (mid<l-1 && nums[mid]>nums[mid+1]) return mid;
            else if (nums[mid]>nums[0]) return findPivot(nums,mid+1,j);
            else if (nums[mid]<nums[0]) return findPivot(nums,i,mid-1);
            else {
                int l = findPivot(nums,i,mid-1);
                int r = findPivot(nums,mid+1,j);
                return (l>r?l:r);
            }
        }else{
            return -1;
        }
    }
};
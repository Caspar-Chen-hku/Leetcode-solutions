class Solution {
public:
    bool search(vector<int>& nums, int target) {
        removeEnd(nums);
        int l = nums.size(), p = findPivot(nums);
        int i, j, mid;
        if (l==0) return false;
        else if (target>=nums[0]){
            i=0; j=p;
        }else{
            i=p+1; j=l-1;
        }
        while (i<=j){
            mid=(i+j)/2;
            if (nums[mid]==target) return true;
            else if (nums[mid]>target) j=mid-1;
            else i=mid+1;
        }
        return false;
    }
    
    void removeEnd(vector<int>& nums){
        int l = nums.size();
        for (int i=l-1; i>0; i--){
            if (nums[i]!=nums[0]) break;
            else nums.pop_back();
        }
    }
    
    int findPivot(vector<int>& nums){
        int l = nums.size(), i=0, j=l-1, mid;
        while (i<=j){
            mid=(i+j)/2;
            if (mid==l-1 || nums[mid]>nums[mid+1]) return mid;
            else if (nums[mid]>=nums[0]) i=mid+1;
            else j=mid-1;
        }
        return 0;
    }
};
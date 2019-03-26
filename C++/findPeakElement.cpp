class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = nums.size();
        if (l==1) return 0;
        int i=0, j=l-1, mid;
        while(i<=j){
            mid = (i+j)/2;
            if (mid>0 && nums[mid]<=nums[mid-1] ){
                j = mid - 1;
            }else if (mid<l-1 && nums[mid]<=nums[mid+1]){
                i = mid +1;
            }else{
                return mid;
            }
        }
        return i;
    }
};
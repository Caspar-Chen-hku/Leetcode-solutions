class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        result.push_back(binSearch1(nums,target));
        result.push_back(binSearch2(nums,target));
        return result;
    }
    
    int binSearch1(vector<int>& nums, int target){
        int i=0, j=nums.size()-1,p;
        while(i<=j){
            p = (i+j)/2;
            if (nums[p]==target){
                if (p==0||nums[p-1]!=target){
                    return p;
                }else j=p-1;
            }
            else if (nums[p]<target) i=p+1;
            else j=p-1;
        }
        return -1;
    }
    
    int binSearch2(vector<int>& nums, int target){
        int s = nums.size();
        int i=0, j=s-1,p;
        while(i<=j){
            p = (i+j)/2;
            if (nums[p]==target){
                if (p==s-1||nums[p+1]!=target){
                    return p;
                }else i=p+1;
            }
            else if (nums[p]<target) i=p+1;
            else j=p-1;
        }
        return -1;
    }
};
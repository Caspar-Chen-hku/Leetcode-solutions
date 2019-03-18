class Solution {
public:
    
    int firstpos(vector<int>& nums){
        int n = nums.size();
        for (int i=0; i<n; i++){
            if (nums[i]>0) return i;
        }
        return -1;
    }
    
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int index = firstpos(nums);
        if (index==-1||nums[index]!=1) return 1;
        int n = nums.size();
        for (int i=index; i<n; i++){
            if ((i<n-1&&nums[i]<nums[i+1]-1)||i==n-1) return nums[i]+1; 
        }
    }
};
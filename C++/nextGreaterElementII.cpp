class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res;
        for (int i=0; i<nums.size(); i++){
            res.push_back(next(nums,i));
        }
        return res;
    }
    
    int next(vector<int>& nums, int ind){
        int l = nums.size();
        for (int i=ind+1; i<ind+l; i++){
            if (nums[i%l]>nums[ind]) return nums[i%l];
        }
        return -1;
    }
};
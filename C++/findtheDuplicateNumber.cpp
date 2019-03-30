class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = nums.size();
        vector<int> arr(l,0);
        for (int i=0; i<l; i++){
            arr[nums[i]]++;
            if (arr[nums[i]]>1) return nums[i];
        }
        return -1;
    }
};
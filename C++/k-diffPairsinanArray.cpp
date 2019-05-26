class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int num = 0, l=nums.size();
        if (l<2) return 0;
        sort(nums.begin(),nums.end());
        for (int i=0; i<l-1; i++){
            if (i>0 && nums[i]==nums[i-1]) continue;
            for (int j=i+1; j<l; j++){
                if (j>i+1 && nums[j]==nums[j-1]) continue;
                else if (nums[j]-nums[i]>k) break;
                else if (nums[j]-nums[i]==k) num++;
            }
        }
        return num;
    }
};
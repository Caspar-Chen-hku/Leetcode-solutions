class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int longest = 1, temp = 1;
        for (int i=1; i<nums.size(); i++){
            if (nums[i]==nums[i-1]+1){
                temp++;
            }else if(nums[i]>nums[i-1]+1){
                if (temp>longest) longest=temp;
                temp = 1;
            }
        }
        return (longest>temp?longest:temp);
    }
};
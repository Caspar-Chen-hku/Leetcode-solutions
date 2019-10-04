class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> res = nums;
        sort(res.begin(), res.end());
        int start=-1, end=-2;
        for (int i=0; i<nums.size(); i++){
            if (nums[i]!=res[i]){
                start = i; break;
            }
        }
        for (int i=nums.size()-1; i>=0; i--){
            if (nums[i]!=res[i]){
                end = i; break;
            }
        }
        return (end-start+1);
    }
};
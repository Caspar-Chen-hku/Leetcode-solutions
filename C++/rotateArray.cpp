class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int l = nums.size();
        k %= l;
        vector<int> temp(nums.begin()+l-k,nums.end());
        nums.erase(nums.begin()+l-k,nums.end());
        nums.insert(nums.begin(),temp.begin(),temp.end());
    }
};
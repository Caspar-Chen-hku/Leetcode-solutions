class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int l = nums.size();
        vector<int> res(l,0);
        if (nums.empty()) return res;
        res[l-1] = 1;
        for (int i=l-2; i>=0; i--){
            res[i] = res[i+1]*nums[i+1];
        }
        int left = 1;
        for (int i=0; i<l; i++){
            res[i] *= left;
            left *= nums[i];
        }
        return res;
    }
};
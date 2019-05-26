class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string res = "";
        int l = nums.size();
        for (int i=0; i<l; i++){
            res += to_string(nums[i]);
            if (i<l-1){
                res += "/";
            }
            if (i==0&&l>2){
                res += "(";
            }
            if (i==l-1 && l>2){
                res += ")";
            }
        }
        return res;
    }
};
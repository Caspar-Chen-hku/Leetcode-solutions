class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty()) return res;
        string cur = to_string(nums[0]);
        int curnum = nums[0], origin = nums[0];
        for (int i=1; i<nums.size(); i++){
            if (nums[i]==curnum+1){
                curnum++;
            }else{
                if (curnum>origin){
                    cur += "->" + to_string(curnum);
                }
                res.push_back(cur);
                curnum = nums[i];
                origin = nums[i];
                cur = to_string(origin);
            }
        }
        if (curnum>origin){
            cur += "->" + to_string(curnum);
        }
        res.push_back(cur);
        return res;
    }
};
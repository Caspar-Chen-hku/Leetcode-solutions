class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> copyNums = nums;
        sort(copyNums.begin(),copyNums.end());
        unordered_map<int,int> m;
        int l = nums.size();
        for (int i=0; i<l; i++){
            m[copyNums[i]] = l-i;
        }
        vector<string> res; int temp;
        for (int i=0; i<l; i++){
            temp = m[nums[i]];
            if (temp==1){
                res.push_back("Gold Medal");
            }else if (temp==2){
                res.push_back("Silver Medal");
            }else if (temp==3){
                res.push_back("Bronze Medal");
            }else{
                res.push_back(to_string(temp));
            }
        }
        return res;
    }
};
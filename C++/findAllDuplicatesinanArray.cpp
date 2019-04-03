class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> twice;
        vector<int> result;
        for (auto n:nums){
            if (twice.count(n)>0){
                result.push_back(n);
            }else{
                twice[n]++;
            }
        }
        return result;
    }
};
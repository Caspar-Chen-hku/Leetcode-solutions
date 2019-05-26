class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,int> occur;
        map<int, vector<int>> omap;
        int maxoccur = 0;
        for (int n:nums){
            occur[n]++;
            maxoccur = max(maxoccur, occur[n]);
        }
        for (int i=0; i<nums.size(); i++){
            if (occur[nums[i]]==maxoccur){
                omap[nums[i]].push_back(i);
            }
        }
        int res = nums.size(), temp;
        for (auto e:omap){
            temp = e.second.back()-e.second[0]+1;
            res = min(res, temp);
        }
        return res;
    }
};
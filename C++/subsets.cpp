class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> cur;
        for (int i=0; i<=nums.size(); i++){
            subsetRec(nums,0,i,sol,cur);
        }
        return sol;
    }
    
    void subsetRec(vector<int>& nums, int start, int count, vector<vector<int>>& sol, vector<int>& cur ){
        int m = nums.size();
        if (count<=0){
            sol.push_back(cur);
            return;
        } else if(start>=m) return;
        for (int i=start; i<m; i++){
            cur.push_back(nums[i]);
            subsetRec(nums,i+1,count-1,sol,cur);
            cur.pop_back();
        }
    }
};
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> sol;
        vector<int> cur;
        int s = nums.size();
        for (int i=0; i<=s; i++){
           subsets(nums,0,i,sol,cur);         
        }
        return sol;
    }
    
    void subsets(vector<int>& nums, int start, int s, vector<vector<int>>& sol, vector<int>& cur){
        int n = nums.size();
        if (start>=n||s<=0){
            vector<int> temp=cur;
            sort(temp.begin(),temp.end());
            if (find(sol.begin(),sol.end(),temp)==sol.end()){
                sol.push_back(temp);
                return;
            }
        }
        for (int i=start; i<n; i++){
            cur.push_back(nums[i]);
            subsets(nums,i+1,s-1,sol,cur);
            cur.pop_back();
        }
    }
};
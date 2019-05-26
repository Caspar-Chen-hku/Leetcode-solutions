class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        set<int> occurred;
        vector<int> cur;
        int sol = 0;
        for (int i=0; i<nums.size(); i++){
            findSet(nums, occurred, cur, sol, i);
        }
        return sol;
    }
    
    void findSet(vector<int>& nums, set<int>& occurred, vector<int>& cur, int& sol, int ind){
        if (occurred.find(ind)==occurred.end()){
            cur.push_back(ind);
            occurred.insert(ind);
            findSet(nums, occurred, cur, sol, nums[ind]);
        }else{
            if (cur.size()>sol){
                sol = cur.size();
            }
            cur.clear();
        }
    }
};
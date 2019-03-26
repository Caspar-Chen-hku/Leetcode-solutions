class Solution {
public:
    vector<vector<int>> res;
    vector<int> tmp;
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum =0, k=0;
        sort(candidates.begin(), candidates.end());
        sumQuestion(sum, target, 0, candidates);
        return res;
    }
    void sumQuestion(int sum, int target, int k, vector<int>& candidates){
        if(target == sum){
            res.push_back(tmp);
            return;
        }
        else if(target < sum)
            return;
        
        for(int i=k; i<candidates.size() && candidates[i] <= target-sum; i++){
            sum += candidates[i];
            tmp.push_back(candidates[i]);
            sumQuestion(sum, target, i, candidates);
            sum -=candidates[i];
            tmp.pop_back();
        }
    }
};
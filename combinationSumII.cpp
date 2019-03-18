class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        return combineSum(candidates.begin(),candidates.end(),target);
    }
    
    vector<vector<int>> combineSum(vector<int>::iterator a, vector<int>::iterator b, int target){
        vector<vector<int>> result;
        vector<int> temp;
        vector<vector<int>> intermediate;
        if (a==b||target<=0){
            return result;
        }
        for (auto i=a; i!=b; i++){
            if (i!=a&&(*i==*(i-1))) continue;
            if (*i==target){
                temp.push_back(target);
                result.push_back(temp);
                temp.clear();
            }else if(*i < target){
                intermediate = combineSum(i+1,b,target-*i);
                if (!intermediate.empty()){
                    intermediate = combine(*i,intermediate);
                    result.insert(result.end(),intermediate.begin(),intermediate.end());
                }                
            }
        }
        return result;
    }
    
    vector<vector<int>> combine(int a, vector<vector<int>> b){
        for (auto i=b.begin(); i!=b.end(); i++){
            (*i).push_back(a);
        }
        return b;
    }
};
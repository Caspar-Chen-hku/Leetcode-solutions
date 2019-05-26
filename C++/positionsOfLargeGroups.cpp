class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        if (S.empty()) return {};
        int curCount = 1;
        char curChar = S[0];
        vector<vector<int>> res;
        S.push_back('-');
        for (int i=1; i<S.length(); i++){
            if (S[i]==curChar){
                curCount++;
            }else{
                if (curCount>=3){
                    res.push_back({i-curCount, i-1});
                }
                curCount = 1; curChar = S[i];
            }
        }
        return res;
    }
};
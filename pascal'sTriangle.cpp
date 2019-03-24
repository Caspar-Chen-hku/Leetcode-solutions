class Solution {
public:
    vector<vector<int>> generate(int num) {
        vector<vector<int>> result;
        for (int i=0; i<num; i++){
            vector<int> temp(i+1,1);
            result.push_back(temp);
        }
        for (int i=2; i<num; i++){
            for (int j=1; j<i; j++){
                result[i][j] = result[i-1][j-1]+result[i-1][j];
            }
        }
        return result;
    }
};
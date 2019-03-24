class Solution {
public:
    vector<int> getRow(int row) {
        vector<vector<int>> result;
        for (int i=0; i<=row; i++){
            vector<int> temp(i+1,1);
            result.push_back(temp);
        }
        for (int i=2; i<=row; i++){
            for (int j=1; j<i; j++){
                result[i][j] = result[i-1][j-1]+result[i-1][j];
            }
        }
        return result[row];
    }
};
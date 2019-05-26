class Solution {
public:
    
    int m;
    int n;
    
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        m = M.size(), n = M[0].size();
        vector<vector<int>> matrix = M;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                matrix[i][j] = average(M, i, j);
            }
        }
        return matrix;
    }
    
    int average(vector<vector<int>>& M, int x, int y){
        int sum = 0, num = 0;
        for (int i=x-1; i<=x+1; i++){
            for (int j=y-1; j<=y+1; j++){
                if (i>=0 && i<m && j>=0 && j<n){
                    sum += M[i][j]; num++;
                }
            }
        }
        return sum/num;
    }
};
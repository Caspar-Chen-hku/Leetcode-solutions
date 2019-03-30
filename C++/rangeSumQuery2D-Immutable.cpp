class NumMatrix {
public:
    
    int** result;
    
    NumMatrix(vector<vector<int>> matrix) {
        if (matrix.empty()) return;
        int m = matrix.size(), n=matrix[0].size();
        result = new int*[m];
        for (int i=0; i<m; i++){
            result[i] = new int[n];
        }
        result[0][0] = matrix[0][0];
        for (int i=1; i<m; i++){
            result[i][0] = result[i-1][0] + matrix[i][0];
        }
        for (int i=1; i<n; i++){
            result[0][i] = result[0][i-1] + matrix[0][i];
        }
        for (int i=1; i<m; i++){
            for (int j=1; j<n; j++){
                result[i][j] = matrix[i][j] + result[i-1][j] 
                    + result[i][j-1] - result[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1==0 && col1==0){
            return result[row2][col2];
        }else if (row1==0){
            return result[row2][col2] - result[row2][col1-1];
        }else if (col1==0){
            return result[row2][col2] - result[row1-1][col2];
        }else{
            return result[row2][col2] - result[row2][col1-1] 
                - result[row1-1][col2] + result[row1-1][col1-1];    
        }
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> zeros;
        int m=matrix.size();
        if (m==0) return;
        int n=matrix[0].size();
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (matrix[i][j]==0){
                    vector<int> vect{i,j};
                    zeros.push_back(vect);                   
                }
            }
        }
        for (int i=0; i<zeros.size(); i++){
            setSingle(matrix,zeros[i]);
        }
    }
    
    void setSingle(vector<vector<int>>& matrix, vector<int> indices){
        for (int i=0; i<matrix.size(); i++){
            matrix[i][indices[1]]=0;
        }
        for (int i=0; i<matrix[0].size(); i++){
            matrix[indices[0]][i]=0;
        }        
    }
};
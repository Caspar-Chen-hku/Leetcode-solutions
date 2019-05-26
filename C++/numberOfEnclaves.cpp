class Solution {
public:
    int m;
    int n;
    
    int numEnclaves(vector<vector<int>>& A) {
        m = A.size(); n = A[0].size();
        for (int i=0; i<n; i++){
            if (A[0][i]==1){
                visit(A, 0, i);
            }
            if (A[m-1][i]==1){
                visit(A, m-1, i);
            }
        }
        for (int i=0; i<m; i++){
            if (A[i][0]==1){
                visit(A, i, 0);
            }
            if (A[i][n-1]==1){
                visit(A, i, n-1);
            }
        }
        int num = 0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                num += A[i][j];
            }
        }
        return num;
    }
    
    void visit(vector<vector<int>>& A, int i, int j){
        A[i][j] = 0;
        if (i>0 && A[i-1][j]==1){
            visit(A, i-1, j);
        }
        if (i<m-1 && A[i+1][j]==1){
            visit(A, i+1, j);
        }
        if (j>0 && A[i][j-1]==1){
            visit(A, i, j-1);
        }
        if (j<n-1 && A[i][j+1]==1){
            visit(A, i, j+1);
        }
    }
};
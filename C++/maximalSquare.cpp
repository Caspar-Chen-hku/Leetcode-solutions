class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int maxarea = 0;
        int m = matrix.size(), n=matrix[0].size();
        int** s = new int*[m];
        for (int i=0; i<m; i++){
            s[i] = new int[n];
        }
        for (int i=0; i<n; i++){
            s[0][i] = matrix[0][i]-'0';
            maxarea = max(maxarea,s[0][i]);
        }
        for (int i=1; i<m; i++){
            s[i][0] = matrix[i][0]-'0';
            maxarea = max(maxarea,s[i][0]);
        }
        for (int i=1; i<m; i++){
            for (int j=1; j<n; j++){
                if (matrix[i][j]=='1'){
                    s[i][j] = min(s[i-1][j],min(s[i][j-1],s[i-1][j-1])) + 1;
                    maxarea = max(maxarea,s[i][j]*s[i][j]);
                }else{
                    s[i][j] = 0;
                }                
            }
        }
        return maxarea;
    }
};
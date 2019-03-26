class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        int m = ob.size(), n=ob[0].size();
        long int** path = new long int*[m];
        if (ob[m-1][n-1]==1) return 0;
        path[m-1] = new long int[n];
        path[m-1][n-1] = 1;
        for (int i=m-2; i>=0; i--) {
            path[i] = new long int[n];
            if (ob[i][n-1]==1) path[i][n-1]=0;
            else path[i][n-1] = path[i+1][n-1];
        }
        for (int i=n-2; i>=0; i--) {
            if (ob[m-1][i]==1) path[m-1][i]=0;
            else path[m-1][i] = path[m-1][i+1];
        }
        for (int i=m-2; i>=0; i--) {
            for (int j=n-2; j>=0; j--){
                if (ob[i][j]==1) path[i][j]=0;
                else path[i][j] = path[i+1][j] + path[i][j+1];
            }
        }
        return path[0][0];
    }
};
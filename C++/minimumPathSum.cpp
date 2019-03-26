class Solution {
public:
    int minPathSum(vector<vector<int>>& ob) {
        int m = ob.size(), n=ob[0].size();
        long int** path = new long int*[m];
        path[m-1] = new long int[n];
        path[m-1][n-1] = ob[m-1][n-1];
        for (int i=m-2; i>=0; i--) {
            path[i] = new long int[n];
            path[i][n-1] = path[i+1][n-1] + ob[i][n-1];
        }
        for (int i=n-2; i>=0; i--) {
            path[m-1][i] = path[m-1][i+1] + ob[m-1][i];
        }
        for (int i=m-2; i>=0; i--) {
            for (int j=n-2; j>=0; j--){
                path[i][j] = min(path[i+1][j],path[i][j+1]) + ob[i][j];
            }
        }
        return path[0][0];
    }
    
    int min(int a,int b){
        return (a>b?b:a);
    }
};
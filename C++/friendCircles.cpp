class Solution {
public:
    int cur = 0;
    
    int findCircleNum(vector<vector<int>>& M) {
        int m = M.size(), n=M[0].size();
        vector<vector<int>> visited(m, vector<int>(n, -1));
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (M[i][j]==1 && visited[i][j]==-1){
                    visit(M,i,j,visited);
                    cur++;
                }
            }
        }
        return cur;
    }
    
    void visit(vector<vector<int>>& M, int x, int y, vector<vector<int>>& visited){
        int m = M.size(), n=M[0].size();
        visited[x][y] = cur;
        for (int i=0; i<n; i++){
            if (M[x][i]==1 && visited[x][i]==-1){
                visit(M, x, i, visited);
            }
        }
        for (int i=0; i<m; i++){
            if (M[i][y]==1 && visited[i][y]==-1){
                visit(M, i, y, visited);
            }
        }
    }
};
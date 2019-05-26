class Solution {
public:
    int m;
    int n;
    vector<vector<bool>> visited;
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea = 0;
        m = grid.size(), n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j]==1 && !visited[i][j]){
                   maxarea = max(maxarea, visit(grid, i ,j)); 
                }
            }
        }
        return maxarea;
    }
    
    int visit(vector<vector<int>>& grid, int i, int j){
        visited[i][j] = 1;
        int res = 1;
        if (i-1>=0 && grid[i-1][j]==1 && !visited[i-1][j]){
            res += visit(grid, i-1, j);
        }
        if (i+1<m && grid[i+1][j]==1 && !visited[i+1][j]){
            res += visit(grid, i+1, j);
        }
        if (j-1>=0 && grid[i][j-1]==1 && !visited[i][j-1]){
            res += visit(grid, i, j-1);
        }
        if (j+1<n && grid[i][j+1]==1 && !visited[i][j+1]){
            res += visit(grid, i, j+1);
        }
        return res;
    }
};
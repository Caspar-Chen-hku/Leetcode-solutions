class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> result;
        if (matrix.empty()) return result;
        int m = matrix.size(), n=matrix[0].size();
        bool** pacific = new bool*[m];
        bool** atlantic = new bool*[m];
        for (int i=0; i<m; i++){
            pacific[i] = new bool[n];
            atlantic[i] = new bool[n];
            for (int j=0; j<n; j++){
                pacific[i][j] = atlantic[i][j] = false;
            }
        }
       
        for (int i=0; i<m; i++){
            dfs(matrix,i,0,pacific);
            dfs(matrix,i,n-1,atlantic);
        }
        for (int i=0; i<n; i++){
            dfs(matrix,0,i,pacific);
            dfs(matrix,m-1,i,atlantic);
        }
        
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (atlantic[i][j] && pacific[i][j]){
                    result.push_back(make_pair(i,j));
                }
            }
        }
        return result;
    }
    
    void dfs(vector<vector<int>>& matrix, int i, int j, bool** visited){
        visited[i][j] = true;
        if (i>0&&matrix[i-1][j]>=matrix[i][j]&&!visited[i-1][j]){
            dfs(matrix,i-1,j,visited);
        }
        if (i<matrix.size()-1 && matrix[i+1][j]>=matrix[i][j]&&!visited[i+1][j]){
            dfs(matrix,i+1,j,visited);
        }
        if (j>0 && matrix[i][j-1]>=matrix[i][j] && !visited[i][j-1]){
            dfs(matrix,i,j-1,visited);
        }
        if (j<matrix[0].size()-1 && matrix[i][j+1]>=matrix[i][j] && !visited[i][j+1]){
            dfs(matrix,i,j+1,visited);
        }
    }
};
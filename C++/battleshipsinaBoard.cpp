class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty()) return 0;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        int num = 0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (board[i][j]=='X' && !visited[i][j]){
                    dfs(board,visited,i,j); num++;
                }
            }
        }
        return num;
    }
    
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j){
        visited[i][j] = true;
        if (i<board.size()-1 && board[i+1][j]=='X' 
            && !visited[i+1][j]) dfs(board,visited,i+1,j);
        else if (j<board[0].size()-1 && board[i][j+1]=='X'
                && !visited[i][j+1]) dfs(board,visited,i,j+1);
    }
};
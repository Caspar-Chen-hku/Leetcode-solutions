class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size(), capture = 0;
        vector<int> r = findRook(board);
        for (int i=r[0]-1; i>=0; i--){
            if (board[i][r[1]]=='B'){
                break;
            }else if (board[i][r[1]]=='p'){
                capture++; break;
            }
        }
        for (int i=r[0]+1; i<m; i++){
            if (board[i][r[1]]=='B'){
                break;
            }else if (board[i][r[1]]=='p'){
                capture++; break;
            }
        }
        for (int i=r[1]-1; i>=0; i--){
            if (board[r[0]][i]=='B'){
                break;
            }else if (board[r[0]][i]=='p'){
                capture++; break;
            }
        }
        for (int i=r[1]+1; i<n; i++){
            if (board[r[0]][i]=='B'){
                break;
            }else if (board[r[0]][i]=='p'){
                capture++; break;
            }
        }
        return capture;
    }
    
    vector<int> findRook(vector<vector<char>>& board){
        int m = board.size(), n = board[0].size();
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (board[i][j]=='R'){
                    return {i, j};
                }
            }
        }
        return {};
    }
    
};
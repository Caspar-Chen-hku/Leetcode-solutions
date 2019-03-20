class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word=="") return true;
        int m=board.size();
        if (m==0) return false;
        int n=board[0].size();
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (board[i][j]==word[0] && exist(board,word,i,j)) return true;
            }
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word, int x, int y){
        if (word=="") return true;
        int m=board.size(), n=board[0].size();
        if (x>=m || x<0 || y>=n || y<0 || board[x][y]!=word[0]) return false;
        string s = word.substr(1);
        board[x][y] = '.';
        bool result = exist(board,s,x+1,y) || exist(board,s,x-1,y) || 
            exist(board,s,x,y+1) || exist(board,s,x,y-1);
        board[x][y] = word[0];
        return result;
    }
};
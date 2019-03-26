
class Solution {
public:
    
    bool whetherUnique(vector<vector<char> >& board, int x1, int y1, int x2, int y2){
        set<char> chars;
        int total = 0;
        for (int i=x1; i<=x2; i++){
            for (int j=y1; j<=y2; j++){
                if (board[i][j]>='0'&&board[i][j]<='9'){
                    total++;
                    chars.insert(board[i][j]);
                }
            }
        }
        if (chars.size()==total) return true;
        else return false;
    }
    
    bool isValidSudoku(vector<vector<char> >& board) {
        for (int i=0; i<9; i++){
            if (!whetherUnique(board,i,0,i,8)) return false;
            if (!whetherUnique(board,0,i,8,i)) return false;
        }
        for (int i=0; i<9; i+=3){
            for (int j=0; j<9; j+=3){
                if (!whetherUnique(board,i,j,i+2,j+2)) return false;
            }
        }
        return true;
    }
};
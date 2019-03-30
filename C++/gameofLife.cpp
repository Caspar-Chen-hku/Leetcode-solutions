class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty()) return;
        vector<vector<int>> nboard = board;
        int temp;
        for (int i=0; i<board.size(); i++){
            for (int j=0; j<board[0].size(); j++){
                temp = numNeighbors(board,i,j);
                if (board[i][j]==1){
                    if (temp<2 || temp>3) nboard[i][j]=0; 
                }else{
                    if (temp==3) nboard[i][j]=1;
                }
            }
        }
        board=nboard;
    }
    
    int numNeighbors(vector<vector<int>>& board, int i, int j){
        int num=0;
        if (i>0){
            if (board[i-1][j]==1) num++;
            if (j>0 && board[i-1][j-1]==1) num++;
            if (j<board[0].size()-1 && board[i-1][j+1]==1) num++;
        }
        if (i<board.size()-1){
            if (board[i+1][j]==1) num++;
            if (j>0 && board[i+1][j-1]==1) num++;
            if (j<board[0].size()-1 && board[i+1][j+1]==1) num++;
        }
        if (j>0 && board[i][j-1]==1) num++;
        if (j<board[0].size()-1 && board[i][j+1]==1) num++;
        return num;
    }
};
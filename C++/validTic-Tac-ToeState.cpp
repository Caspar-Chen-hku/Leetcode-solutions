class Solution {
public:
    int howMany(vector<string>& board, char c) {
        int count = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] == c)
                    count++;
        return count;
    }
    
    int checkWins(vector<string>& board, char c) {
        int wins = 0;
        
        // Check rows and columns
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == c && board[i][1] == c && board[i][2] == c)
                wins++;
            if (board[0][i] == c && board[1][i] == c && board[2][i] == c)
                wins++;
        }
        
        // Check diagonals
        if (board[0][0] == c && board[1][1] == c && board[2][2] == c)
            wins++;
        if (board[0][2] == c && board[1][1] == c && board[2][0] == c)
            wins++;
        
        return wins;
    }
    
    bool validTicTacToe(vector<string>& board) {
        int numO = howMany(board, 'O');
        int numX = howMany(board, 'X');
        int winO = checkWins(board, 'O');
        int winX = checkWins(board, 'X');
        
        if (numO > numX || numO < numX-1)
            return false;
        
        if (numX > 5 || numO > 4)
            return false;
        
        if (winX && winO)
            return false;
        
        if (winX) {
            if (winX == 1 && winO == 0)
                if (numX != numO + 1)
                    return false;
            if (winX == 2)
                if (numX != 5 && numO != 4)
                    return false;
        }
        
        if (winO) {
            if (winO == 1 && winX == 0)
                if (numO != numX)
                    return false;
            if (winO >= 2)
                return false;
        }
        
        return true;
    }
};
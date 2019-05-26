class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board.empty() || board[0].empty()) return {};
        int m = board.size(), n = board[0].size(), row = click[0], col = click[1], cnt = 0;
        if (board[row][col] == 'M') {
            board[row][col] = 'X';
        } else {
            for (int i = -1; i < 2; ++i) {
                for (int j = -1; j < 2; ++j) {
                    int x = row + i, y = col + j;
                    if (x < 0 || x >= m || y < 0 || y >= n) continue;
                    if (board[x][y] == 'M') ++cnt;
                }
            }
            if (cnt > 0) {
                board[row][col] = cnt + '0';
            } else {
                board[row][col] = 'B';
                for (int i = -1; i < 2; ++i) {
                    for (int j = -1; j < 2; ++j) {
                        int x = row + i, y = col + j;
                        if (x < 0 || x >= m || y < 0 || y >= n) continue;
                        if (board[x][y] == 'E') {
                            vector<int> nextPos{x, y};
                            updateBoard(board, nextPos);
                        }
                    }
                }
            }
        }
        return board;
    }
};
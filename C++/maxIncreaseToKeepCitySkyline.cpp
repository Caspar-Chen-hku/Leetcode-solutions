class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> leftLine(m, 0);
        vector<int> topLine(n, 0);
        int curMax = 0;
        for (int i=0; i<m; i++){
            curMax = 0;
            for (int j=0; j<n; j++){
                curMax = max(curMax, grid[i][j]);
            }
            leftLine[i] = curMax;
        }
        for (int j=0; j<n; j++){
            curMax = 0;
            for (int i=0; i<m; i++){
                curMax = max(curMax, grid[i][j]);
            }
            topLine[j] = curMax;
        }
        int ans = 0;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                ans += min(leftLine[i],topLine[j])-grid[i][j];
            }
        }
        return ans;
    }
};
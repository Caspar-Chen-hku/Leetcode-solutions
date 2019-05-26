class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int area = 0, maxRow, maxCol;
        int m = grid.size(), n = grid[0].size();
        for (int i=0; i<m; i++){
            maxRow = 0;
            for (int j=0; j<n; j++){
                if (grid[i][j]>0) area++;
                maxRow = max(maxRow, grid[i][j]);
            }
            area += maxRow;
        }
        for (int j=0; j<n; j++){
            maxCol = 0;
            for (int i=0; i<m; i++){
                maxCol = max(maxCol, grid[i][j]);
            }
            area += maxCol;
        }
        return area;
    }
};
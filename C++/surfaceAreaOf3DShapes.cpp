class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int area = 0, maxRow, maxCol;
        for (int i=0; i<grid.size(); i++){
            maxRow = 0;
            for (int j=0; j<grid[0].size(); j++){
                if (grid[i][j]>0) area+=2;
                area += abs(maxRow-grid[i][j]);
                maxRow = grid[i][j];
            }
            area += maxRow;
        }
        for (int j=0; j<grid[0].size(); j++){
            maxCol = 0;
            for (int i=0; i<grid.size(); i++){
                area += abs(maxCol-grid[i][j]);
                maxCol = grid[i][j];
            }
            area += maxCol;
        }
        return area;
    }
};
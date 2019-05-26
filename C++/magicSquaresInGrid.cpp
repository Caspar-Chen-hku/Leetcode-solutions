class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count = 0;
        int m = grid.size(), n=grid[0].size();
        if (m<3 || n<3) return 0;
        for (int i=0; i<m-2; i++){
            for (int j=0; j<n-2; j++){
                if (grid[i+1][j+1]!=5) continue;
                else if (magic(grid,i,j)) count++;
            }
        }
        return count;
    }
    
    bool magic(vector<vector<int>>& grid, int i, int j){
        set<int> nums;
        for (int x=i; x<i+3; x++){
            for (int y=j; y<j+3; y++){
                if (grid[x][y]<1 || grid[x][y]>9 || nums.find(grid[x][y])!=nums.end()){
                    return false;
                }else{
                    nums.insert(grid[x][y]);
                }
            }
        }
        return (grid[i][j]+grid[i][j+1]+grid[i][j+2]==15 &&
                        grid[i+1][j]+grid[i+1][j+2]==10 &&
                        grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2]==15 &&
                        grid[i][j]+grid[i+1][j]+grid[i+2][j]==15 &&
                        grid[i][j+1]+grid[i+2][j+1]==10 &&
                        grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2]==15 &&
                        grid[i][j]+grid[i+2][j+2]==10 &&
                        grid[i][j+2]+grid[i+2][j]==10);
        
    }
};
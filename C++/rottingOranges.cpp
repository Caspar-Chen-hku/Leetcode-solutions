class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        int m = grid.size(), n = grid[0].size();
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int num = 0;
        bool entered;
        vector<int> temp;
        while (!q.empty()){
            entered = false;
            for (int i=q.size(); i>0;  i--){
                temp = q.front();
                if (temp[0]>0 && grid[temp[0]-1][temp[1]]==1){
                    grid[temp[0]-1][temp[1]]=2;
                    q.push({temp[0]-1, temp[1]});
                    entered = true;
                }
                if (temp[0]<m-1 && grid[temp[0]+1][temp[1]]==1){
                    grid[temp[0]+1][temp[1]]=2;
                    q.push({temp[0]+1, temp[1]});
                    entered = true;
                }
                if (temp[1]>0 && grid[temp[0]][temp[1]-1]==1){
                    grid[temp[0]][temp[1]-1]=2;
                    q.push({temp[0], temp[1]-1});
                    entered = true;
                }
                if (temp[1]<n-1 && grid[temp[0]][temp[1]+1]==1){
                    grid[temp[0]][temp[1]+1]=2;
                    q.push({temp[0], temp[1]+1});
                    entered = true;
                }
                q.pop();
            }
            if (entered) num++;
        }
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (grid[i][j]==1){
                    return -1;
                }
            }
        }
        return num;
    }
};
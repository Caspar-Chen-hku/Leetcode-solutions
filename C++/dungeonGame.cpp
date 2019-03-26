//1: up, -1: left
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        int** power = new int*[m];
        for (int i=0; i<m; i++){
            power[i] = new int[n];
        }
        if (dungeon[m-1][n-1]<0){
            power[m-1][n-1] = 1 - dungeon[m-1][n-1]; 
        }else{
            power[m-1][n-1] = 1;  
        }
        for (int i=m-2; i>=0; i--){
            power[i][n-1] = max(power[i+1][n-1] - dungeon[i][n-1],1);
        }
        for (int i=n-2; i>=0; i--){
            power[m-1][i] = max(power[m-1][i+1] - dungeon[m-1][i],1);
        }
        for (int i=m-2; i>=0; i--){
            for (int j=n-2; j>=0; j--){
                power[i][j] = min(power[i+1][j],power[i][j+1]);
                power[i][j] = max(power[i][j]-dungeon[i][j], 1);
            }
        }
        return power[0][0];
    }
};
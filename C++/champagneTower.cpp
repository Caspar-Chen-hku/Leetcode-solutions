class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> flow(query_row+1, vector<double>(query_row+1, 0));
        flow[0][0] = poured;
        for (int i=1; i<=query_row; i++){
            for (int j=0; j<=i; j++){
                if (j>0){
                    flow[i][j] += max(0.0, (flow[i-1][j-1]-1)/2);
                }
                if (j<i){
                    flow[i][j] += max(0.0, (flow[i-1][j]-1)/2);
                }
            }
        }
        return min(1.0, flow[query_row][query_glass]);
    }
};
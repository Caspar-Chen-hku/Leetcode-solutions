class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int l = points.size();
        vector<vector<long>> distance(l, vector<long>(l, 0));
        for (int i=0; i<l-1; i++){
            for (int j=i+1; j<l; j++){
                distance[i][j] = distance[j][i] = 
                    pow((points[i].first-points[j].first),2)+
                    pow((points[i].second-points[j].second),2);
            }
        }
        int count = 0;
        for (int i=0; i<l; i++){
            for (int j=0; j<l-1; j++){
                if (j==i) continue;
                for (int k=j+1; k<l; k++){
                    if (k==i) continue;
                    if (distance[i][j]==distance[i][k]) count+=2;
                }
            }
        }
        return count;
    }
};
class Solution {
public:
    
    static bool compare(vector<int>& a, vector<int>& b){
        return a[0]-a[1] < b[0]-b[1];
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), compare);
        int cost = 0, l = costs.size();
        for (int i=0; i<l/2; i++){
            cost += costs[i][0];
        }
        for (int i=l/2; i<l; i++){
            cost += costs[i][1];
        }
        return cost;
    }
};
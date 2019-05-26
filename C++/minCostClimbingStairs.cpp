class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int l = cost.size();
        int* stair = new int[l];
        stair[0] = cost[0];
        stair[1] = cost[1];
        for (int i=2; i<l; i++){
            stair[i] = min(stair[i-1],stair[i-2]) + cost[i];
        }
        return min(stair[l-1], stair[l-2]);
    }
};
class Solution {
public:
    vector<bool> visited;
    map<int,vector<pair<int,int>>> fly;
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        for (vector<int> e:flights){
            fly[e[0]].push_back(make_pair(e[1],e[2]));
        }
        visited = vector<bool>(n, false);
        visited[src] = true;
        int minCost = INT_MAX;
        visit(src, dst, K, -1, 0, minCost);
        return (minCost == INT_MAX ? -1 : minCost);
    }
    
    void visit(int src, int dst, int K, int curStep, int curCost, int& minCost){
        if (src==dst){
            if (curStep<=K && curCost<minCost){
                minCost = curCost;
            }
            return;
        }else if(curCost>=minCost || curStep>=K){
            return;
        }
        for (pair<int,int> p:fly[src]){
            if (!visited[p.first]){
                visited[p.first] = true;
                visit(p.first, dst, K, curStep+1, curCost+p.second, minCost);
                visited[p.first] = false;
            }
        }
    }
};
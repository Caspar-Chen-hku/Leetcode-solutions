class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        bool* visited = new bool[n];
        int curmin = n, maxcost = 0;
        vector<int> results;
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                visited[j] = false;
            }
            maxcost = 0;
            dfs(i,edges,visited,0, maxcost,0,n);
            cout << maxcost << "\t";
            results.push_back(maxcost);
            if (maxcost<curmin) curmin=maxcost;
        }
        vector<int> sol;
        for (int i=0; i<n; i++){
            if (results[i]==curmin) sol.push_back(i);
        }
        return sol;
    }
    
    void dfs(int tovisit, vector<pair<int, int>>& edges, bool* visited, int cost, int& maxcost, int numvisited, int n){
        visited[tovisit] = true; numvisited++;
        if (cost>maxcost) maxcost=cost;
        if (numvisited==n) return;
        for (auto it=edges.begin(); it!=edges.end(); it++){
            if (it->second == tovisit && !visited[it->first]){
                dfs(it->first, edges, visited, cost+1, maxcost, numvisited, n);
            }
            else if (it->first == tovisit && !visited[it->second]){
                dfs(it->second, edges, visited, cost+1, maxcost, numvisited, n);
            }
        }
    }
};
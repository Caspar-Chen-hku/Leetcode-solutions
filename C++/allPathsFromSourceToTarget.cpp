class Solution {
public:
    
    vector<bool> visited;
    int n;
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        visited = vector<bool>(n, false);
        vector<int> curPath;
        vector<vector<int>> sol;
        paths(graph, 0, curPath, sol);
        return sol;
    }
    
    void paths(vector<vector<int>>& graph, int src, 
               vector<int>& curPath, vector<vector<int>>& sol){
        visited[src] = true; curPath.push_back(src);
        if (src==n-1){
            sol.push_back(curPath); 
            visited[src] = false; curPath.pop_back();
            return;
        }
        for (int next:graph[src]){
            if (!visited[next]){
                paths(graph, next, curPath, sol);
            }
        }
        visited[src] = false; curPath.pop_back();
    }
};
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> res;
        if(n == 1){
            res = {0};
            return res;
        }
        vector<int> degree(n);
        vector<vector<int>> adj(n);
        for(auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]] ++;
            degree[edge[1]] ++;
        }
        
        queue<int> myq, nextq;
        for(int i = 0; i < n; ++ i){
            if(degree[i] == 1){
                myq.push(i);
            }
        }
        
        while(!myq.empty()){
            res.clear();
            auto size = myq.size();
            for(auto i = 0; i < size; ++ i){
                int cur = myq.front();
                myq.pop();
                res.push_back(cur);
                for(int j: adj[cur]){
                    degree[j] --;
                    if(degree[j] == 1)
                        myq.push(j);
                }
            }
        }
        return res;
    }
};
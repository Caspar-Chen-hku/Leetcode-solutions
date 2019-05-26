class Solution {
public:
    
    vector<int> visited;
    map<int, set<int>> dis;
    int n;
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        visited = vector<int>(N+1, -1);
        for (vector<int> d:dislikes){
            dis[d[0]].insert(d[1]);
            dis[d[1]].insert(d[0]);
        }
        n = N;
        for (int i=1; i<=n; i++){
            if (visited[i]==-1 && !visit(i, 0)){
                return false;
            }
        }
        return true;
    }
    
    bool visit(int cur, int num){
        visited[cur] = num;
        for (int i:dis[cur]){
            if (visited[i]==num) return false;
            else if (visited[i]==-1 && !visit(i, (num+1)%2)) return false;
        }
        return true;
    }
};
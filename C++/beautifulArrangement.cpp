class Solution {
public:
    int countArrangement(int N) {
        vector<bool> visited(N, false);
        int res = 0;
        count(N, 0, visited, res);
        return res;
    }
    
    void count(int N, int cur, vector<bool>& visited, int& res){
        if (cur==N){
            res++; return;
        }
        for (int i=1; i<=N; i++){
            if (!visited[i-1] && (i%(cur+1)==0 || (cur+1)%i==0)){
                visited[i-1]=true;
                count(N, cur+1, visited, res);
                visited[i-1]=false;
            }
        }
    }
};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        queue<pair<int,int> >q;
        pair<int,int>p;
        int m=mat.size();
        int n=mat[0].size();
       
        vector<vector<int> >vis(m,vector<int>(n,INT_MAX));
        
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j] == 0){
                    vis[i][j]=0;
                    q.push({i,j});
                }
            }
        }   
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        while(!q.empty()){
            p=q.front();
            q.pop();
            int x=p.first;
            int y=p.second;
            int xnew,ynew;
            for(int i=0;i<4;i++){
                xnew=x+dx[i];
                ynew=y+dy[i];
                if(xnew <0 || ynew <0 || xnew>=m || ynew >= n)
                    continue;
                if(vis[xnew][ynew] > vis[x][y]+1){
                    vis[xnew][ynew] = vis[x][y]+1;
                    q.push({xnew,ynew});
                }
            }
        }
        return vis;
    }
};
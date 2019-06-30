class Solution {
public:

    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {        
        vector<int> edge[10010];
        for(int i=0;i<paths.size();i++)
        {
            int x = paths[i][0];
            int y = paths[i][1];
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        
        vector<int> ans(N,0);
        
        for(int i=1;i<=N;i++)
        {
            ans[i-1]=gao(edge[i],ans);
        }
        
        return ans;
    }
    
    int gao(vector<int> edge,vector<int> ans)
    {
        for(int num=1;num<=4;num++)
        {
            bool flag = false;
            for(int j=0;j<edge.size();j++)
            {
                if(ans[edge[j]-1] == num)
                {
                    flag = true;
                    break;
                }
            }
            if(flag == false)
                return num;
        }
        return 0;
    }
};
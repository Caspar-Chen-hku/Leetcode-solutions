class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {

        int ans[N+1];
        memset(ans, -1, sizeof(ans));
        vector<vector< pair<int, int> >  > adj_list;
        for(int i=0;i<N+1;++i)
        {
            vector<pair<int,int> > temp;
            adj_list.push_back(temp);
        }
        for(int i=0;i<times.size();++i)
        {
            int node1 = times[i][0];
            int node2 = times[i][1];
            int w = times[i][2];

            adj_list[node1].push_back(make_pair(node2, w));
        }

        ans[K] = 0;
        queue<int> q;
        q.push(K);

        while(!q.empty())
        {
            int cur_node = q.front();
            q.pop();

            for(int i=0;i<adj_list[cur_node].size();++i)
            {
                int adj_node = adj_list[cur_node][i].first;
                int w = adj_list[cur_node][i].second;

                if(ans[adj_node]==-1 || ans[adj_node]>ans[cur_node]+w)
                    {
                        ans[adj_node] = ans[cur_node] + w;
                        q.push(adj_node);
                    }
            }
        }

        int final_ans = ans[1];

        for(int i=1;i<N+1;++i)
        {
            if(ans[i]==-1)
                return -1;
            final_ans = max(final_ans, ans[i]);
        }

        return final_ans;
    }
};
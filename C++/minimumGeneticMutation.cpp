class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        bank.insert(bank.begin(),start);
        vector<vector<bool>> dist(bank.size(),vector<bool>(bank.size(),false));
        for (int i=0; i<bank.size()-1; i++){
            for (int j=i+1; j<bank.size(); j++){
                dist[i][j] = dist[j][i] = distance(bank[i],bank[j]);
            }
        }
        vector<bool> visited(bank.size(),false);
        queue<int> cur;
        cur.push(0);
        int count = 0, temp;
        while (!cur.empty()){
            for (int i=cur.size(); i>0; i--){
                temp = cur.front();
                visited[temp] = true;
                if (bank[temp]==end) return count;
                for (int j=1; j<bank.size(); j++){
                    if ( !visited[j] && dist[temp][j]) cur.push(j);
                }
                cur.pop();
            }
            count++;
        }
        return -1;
    }
    
    bool distance(string a, string b){
        int num = 0;
        for (int i=0; i<8; i++){
            if (a[i]!=b[i]) num++;
            if (num>1) return false;
        }
        return true;
    }
};
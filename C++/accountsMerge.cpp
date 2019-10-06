class Solution {
public:
    
    int find(vector<int>& union_find, int idx){
        if(union_find[idx] == -1)   return idx;
        return find(union_find,union_find[idx]);
    }
    
    void Union(vector<int>&union_find, int idx1, int idx2){
        int parent1 = find(union_find,idx1);
        int parent2 = find(union_find,idx2);
        if(parent1 != parent2)  union_find[parent1] = parent2;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        int n = accounts.size();
        
        vector<int> union_find(n,-1);
        map<string,int> mailUser;
        map<int,vector<string>> mails;
        
        for(int i=0; i<accounts.size(); i++){
            for(int j=1; j<accounts[i].size(); j++){
                if(mailUser.count(accounts[i][j])){
                    int idx1 = find(union_find,i);
                    int idx2 = find(union_find,mailUser[accounts[i][j]]);
                    Union(union_find,idx1,idx2);
                }
                mailUser[accounts[i][j]] = i;
            }
        }
        
        for(auto pair:mailUser){
            int user = find(union_find,pair.second);
            mails[user].push_back(pair.first);
        }
        
        for(auto pair:mails){
            vector<string> temp = pair.second;
            sort(temp.begin(),temp.end());
            temp.insert(temp.begin(),accounts[pair.first][0]);
            res.push_back(temp); 
        }
        
        return res;
    }
};
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int l = s.length(), wl=wordDict.size(), temp;
        vector<string>* sol = new vector<string>[l+1];
        for (int i=0; i<wl; i++){
            temp = wordDict[i].length();
            if (s.find(wordDict[i])==0){
                sol[temp].push_back(wordDict[i]);
            }
        }
        vector<string>::iterator it;
        for (int i=2; i<=l; i++){
            for (int j=1; j<i; j++){
                if (!sol[j].empty()){
                    it = find(wordDict.begin(),wordDict.end(),s.substr(j,i-j));
                    if (it!=wordDict.end()){
                        sol[i].push_back(*it);
                    }
                } 
            }
        }
        string cur = "";
        vector<string> result;
        dfs(sol,cur,l,result);
        return result;
    }
    
    void dfs(vector<string>* sol, string& cur, int ind, vector<string>& result){
        int l = sol[ind].size(), curlen = cur.length();
        if (ind==0){
            cur.pop_back();
            result.push_back(cur);
            return;
        }
        string temp = cur;
        for (int i=0; i<l; i++){
            cur = sol[ind][i] + " " + cur;
            dfs(sol,cur,ind-sol[ind][i].length(), result);
            cur = temp;
        }
    }
};
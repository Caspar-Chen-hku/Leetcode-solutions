class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        vector<vector<string>> sol;
        part(s,0,cur,sol);
        return sol;
    }
    
    void part(string s, int ind, vector<string>& cur, vector<vector<string>>& sol){
        int l = s.length();
        if (ind == l){
            sol.push_back(cur);
            return;
        }
        
        string temp;
        for (int i=1; i<=l-ind; i++){
            temp = s.substr(ind,i);
            if (palin(temp)){
                cur.push_back(temp);
                part(s,ind+i,cur,sol);
                cur.pop_back();
            }            
        }
    }
    
    bool palin(string s){
        int l = s.length();
        for (int i=0; i<l/2; i++){
            if (s[i]!=s[l-i-1]){
                return false;
            }
        }
        return true;
    }
};
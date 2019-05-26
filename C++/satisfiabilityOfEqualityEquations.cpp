class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<set<int>> equals(26, set<int>());
        vector<set<int>> unequals(26, set<int>());
        for (string e:equations){
            if (e[1]=='='){
                equals[e[0]-'a'].insert(e[3]-'a');
                equals[e[3]-'a'].insert(e[0]-'a');
            }else{
                unequals[e[0]-'a'].insert(e[3]-'a');
                unequals[e[3]-'a'].insert(e[0]-'a');
            }
        }
        int curval = 0;
        vector<int> visited(26, -1);
        for (int i=0; i<26; i++){
            if (visited[i]==-1){
                visit(equals, visited, i, curval);
                curval++;
            }   
        }
        for (int i=0; i<26; i++){
            if (visited[i]==-1) continue;
            for (int j=i; j<26; j++){
                if (visited[i]==visited[j] && unequals[i].find(j)!=unequals[i].end()){
                    return false;
                }
            }
        }
        return true;
    }
    
    void visit(vector<set<int>> equals, vector<int>& visited, int ind, int val){
        visited[ind] = val;
        for (int i:equals[ind]){
            if (visited[i]==-1){
                visit(equals, visited, i, val);
            }
        }
    }
};
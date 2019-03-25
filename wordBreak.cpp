class Solution {
public:
    bool wordBreak(string s, vector<string>& w) {
        int l =s.length();
        bool* sol = new bool[l+1];
        sol[0]=true;
        for (int i=1; i<=l; i++){
            sol[i]=false;
            for (int j=0; j<i; j++){
                if (sol[j] && 
                    find(w.begin(), w.end(), s.substr(j,i-j)) != w.end()){
                    sol[i]=true; break;
                }
            }
        }
        return sol[l];
    }
};
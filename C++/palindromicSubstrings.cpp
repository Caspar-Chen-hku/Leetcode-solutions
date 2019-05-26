class Solution {
public:
    int countSubstrings(string s) {
        int l = s.length(), num = l;
        vector<vector<bool>> palin(l, vector<bool>(l, true));
        for (int len=1; len<l; len++){
            for (int i=0; i<l-len; i++){
                if (s[i]==s[i+len] && palin[i+1][i+len-1]){
                    palin[i][i+len]=true; num++;
                }else{
                    palin[i][i+len]=false;
                }
            }
        }
        return num;
    }
};
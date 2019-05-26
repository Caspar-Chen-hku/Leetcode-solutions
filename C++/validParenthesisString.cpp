class Solution {
public:
    bool checkValidString(string s) {
        int l = s.length();
        if (l==0) return true;
        vector<vector<bool>> valid(l, vector<bool>(l, true));
        for (int i=0; i<l; i++){
            valid[i][i] = (s[i]=='*');
        }
        for (int len=1; len<l; len++){
            for (int i=0; i<l-len; i++){
                if (s[i]==')'){
                    valid[i][i+len]=false; continue;
                }
                valid[i][i+len] = (s[i]=='*' && valid[i+1][i+len]);
                if (!valid[i][i+len]){
                    for (int j=i+1; j<=i+len; j++){
                        if (s[j]!=')'&&s[j]!='*') continue;
                        else if (valid[i+1][j-1] && (j==l-1 || valid[j+1][i+len])){
                            valid[i][i+len] = true; break;
                        }
                    }
                }
            }
        }
        return valid[0][l-1];
    }
};
class Solution {
public:
    bool isMatch(string s, string p) {
        int lp = p.length();
        int ls = s.length();
        if (ls==0){
            if (lp==0){
                return true;
            }else if (lp>1&&p[1]=='*'){
                return isMatch(s,p.substr(2));
            }else{
                return false;
            }
        }else if (lp==0){
            return false;
        }
        if (lp==1||p[1]!='*'){
            bool temp = isMatch(s.substr(1),p.substr(1));
            if (p[0]=='.'){
                return temp;
            }else{
                return (s[0]==p[0]&&temp);
            }
        }else{
            int m = maxmatch(s,p[0]);
            for (int i=0; i<=m; i++){
                if (isMatch(s.substr(i),p.substr(2))){
                    return true;
                }
            }
            return false;
        }
    }
    
    int maxmatch(string s, char c){
        if (c=='.'){
            return s.length();
        }else{
            int result = 0;
            for (int i=0; i<s.length(); i++){
                if (s[i]==c){
                    result++;
                }else{
                    break;
                }
            }
            return result;
        }
    }
};
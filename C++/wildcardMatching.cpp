class Solution {
public:
    bool isMatch(string s, string p) {
        int ls = s.length();
        int lp = p.length();
        bool** match = new bool*[ls+1];
        for (int i=0; i<=ls; i++){
            match[i] = new bool[lp+1];
            for (int j=0; j<=lp; j++){
                match[i][j] = false;
            }
        }
        match[0][0] = true;
        for (int i=0; i<lp; i++){
            if (p[i]!='*') break;
            match[0][i+1] = true;
        }
        for (int i=0; i<ls; i++){
            for (int j=0; j<lp; j++){
                if (s[i]==p[j]||p[j]=='?'){
                    match[i+1][j+1] = match[i][j];
                }else if (p[j]=='*'){
                    match[i+1][j+1] = match[i+1][j+1] || 
                        match[i][j+1] || match[i+1][j];
                }else{
                    match[i+1][j+1] = false;
                }
            }
        }
        return match[ls][lp];
    }
};
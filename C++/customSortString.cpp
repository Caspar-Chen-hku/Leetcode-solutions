
class Solution {
public:
    
    map<char,int> pos;
    
    string customSortString(string S, string T) {
        for (int i=0; i<S.length(); i++){
            pos[S[i]] = i;
        }
        return sortStr(T);
    }
    
    string sortStr(string t){
        int l = t.length();
        if (l < 2){
            return t;
        }else{
            string t1 = sortStr(t.substr(0, l/2));
            string t2 = sortStr(t.substr(l/2));
            string res = "";
            int i=0, j=0;
            while (i<l/2 && j<l-l/2){
                if (pos[t1[i]] < pos[t2[j]]){
                    res.push_back(t1[i]); i++;
                }else{
                    res.push_back(t2[j]); j++;
                }
            }
            if (i<l/2){
                res += t1.substr(i);
            }else if (j<l-l/2){
                res += t2.substr(j);
            }
            return res;
        }
    }
};
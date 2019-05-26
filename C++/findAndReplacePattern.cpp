class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        map<char,char> m;
        set<char> mapped;
        vector<string> res;
        bool exist = true;
        int pl = pattern.length();
        for (string s:words){
            if (s.length()!=pl) continue;
            exist = true; m.clear(); mapped.clear();
            for (int i=0; i<pl; i++){
                if (m.count(s[i])==0){
                    if (mapped.find(pattern[i])!=mapped.end()){
                        exist = false; break;
                    }
                    m[s[i]] = pattern[i];
                    mapped.insert(pattern[i]);
                }else if (m[s[i]]!=pattern[i]){
                    exist = false; break;
                }
            }
            if (exist){
                res.push_back(s);
            }
        }
        return res;
    }
};
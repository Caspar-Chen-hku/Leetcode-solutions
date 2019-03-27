class Solution {
    public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> sm;
        unordered_map<char,char>::const_iterator it;
        for (int i = 0; i < s.length(); i++)
        {
            it = sm.find(s[i]);
            if (it == sm.end()) {
                for (it = sm.begin(); it != sm.end(); it++) {
                    if (it->second == t[i])
                        return false;
                }
                sm.insert(pair(s[i],t[i]));
                s[i] = t[i];
            }
            else {
                s[i] = it->second;    
            }
        }
        if(!s.compare(t)) {
            return true;
        }
        return false;    
    }
};
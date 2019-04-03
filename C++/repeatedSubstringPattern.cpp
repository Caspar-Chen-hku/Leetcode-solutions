class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int l = s.length();
        string s1 = s+s;
        s1 = s1.substr(1,l*2-2);
        return (s1.find(s)!=string::npos);
    }
};
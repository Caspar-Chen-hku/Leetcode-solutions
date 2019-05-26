class Solution {
public:
    bool checkRecord(string s) {
        if (s.empty()) return true;
        int counta = 0, countl = 0;
        for (int i=0; i<s.length(); i++){
            if (s[i]=='L'){
                if (++countl>2) return false;
                continue;
            }
            countl = 0;
            if (s[i]=='A'){
                if (++counta>1) return false;
            }
        }
        return true;
    }
};
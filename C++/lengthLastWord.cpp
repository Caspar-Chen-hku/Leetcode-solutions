class Solution {
public:
    int lengthOfLastWord(string s) {
        int l = 0;
        int lastInd;
        for (int i=s.length()-1; i>=0; i--){
            if (s[i]!=' '){
                lastInd = i; break;
            }
        }
        for (int i=lastInd; i>=0; i--){
            if (s[i]!=' ') l++;
            else break;
        }
        return l;
    }
};
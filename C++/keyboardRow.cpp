class Solution {
public:
    
    vector<string> comp={"qQwWeErRtTyYuUiIoOpP","aAsSdDfFgGhHjJkKlL","ZzXxCcVvBbNnMm"};
    
    vector<string> findWords(vector<string>& words) {
        int cur; bool equal;
        vector<string> res;
        for (string s:words){
            cur = findInComp(s[0]); equal=true;
            for (int i=1; i<s.length(); i++){
                if (findInComp(s[i])!=cur) {
                    equal=false; break;
                }
            }
            if (equal) res.push_back(s);
        }
        return res;
    }
    
    int findInComp(char c){
        for (int i=0; i<3; i++){
            if (comp[i].find(c)!=string::npos) return i;
        }
        return -1;
    }
};
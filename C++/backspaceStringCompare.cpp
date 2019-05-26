class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return (res(S)==res(T));
    }
    
    string res(string S){
        string s = "";
        for (char c:S){
            if (c=='#'){
                if (!s.empty()) s.pop_back();
            }else{
                s.push_back(c);
            }
        }
        return s;
    }
};
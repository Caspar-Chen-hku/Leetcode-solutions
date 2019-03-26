class Solution {
public:
    bool isValid(string s) {
        if (s=="") return true;
        stack<char> paras;
        int l = s.length();
        paras.push(s[0]);
        for (int i=1; i<l; i++){
            if (!paras.empty() && match(paras.top(),s[i])){
                paras.pop();
            }else{
                paras.push(s[i]);
            }
        }
        return paras.empty();
    }
    
    bool match(char a, char b){
        return ((a=='('&&b==')') || (a=='{'&&b=='}') || (a=='['&&b==']'));
    }
};
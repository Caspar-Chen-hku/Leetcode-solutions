class Solution {
public:
    string maskPII(string S) {
        int at = S.find("@");
        if (at!=string::npos){
            return maskEmail(S, at);
        }else{
            return maskPhone(S);
        }
    }
    
    string maskEmail(string s, int at){
        string res;
        res.push_back(tolower(s[0]));
        res += "*****";
        res.push_back(tolower(s[at-1]));
        for (int i=at; i<s.length(); i++){
            res.push_back(tolower(s[i]));
        }
        return res;
    }
    
    string maskPhone(string s){
        string nums = "";
        string res = "";
        int count = 0;
        for (char c:s){
            if (c>='0' && c<='9'){
                nums.push_back(c); count++;
            }
        }
        if (count>10){
            res = "+";
            res += string(count-10, '*');
            res.push_back('-');
        }
        res += "***-***-";
        res += nums.substr(count-4);
        return res;
    }
};
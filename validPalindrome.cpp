class Solution {
public:
    bool isPalindrome(string s) {
        string converted = convert(s);
        int l = converted.length();
        for (int i=0; i<l/2; i++){
            if (converted[i]!=converted[l-i-1]){
                return false;
            }
        }
        return true;
    }
    
    string convert(string s){
        string result = "";
        for (int i=0; i<s.length(); i++){
            if ((s[i]>='0'&&s[i]<='9') || (s[i]>='a'&&s[i]<='z')){
                result.push_back(s[i]);
            }else if (s[i]>='A'&&s[i]<='Z'){
                result.push_back(s[i]+('a'-'A'));
            }
        }
        return result;
    }
};
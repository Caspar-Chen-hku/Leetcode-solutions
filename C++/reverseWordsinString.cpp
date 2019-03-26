class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        int ind = 0, l=s.length();
        for (int i=0; i<l; i++){
            if (s[i]==' '){
                ind = i+1;
            }else if(i==l-1 || s[i+1]==' '){
                result = s.substr(ind,i-ind+1) + " " + result;
            }
        }
        result.pop_back();
        return result;
    }
};
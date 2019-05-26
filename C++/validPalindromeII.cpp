class Solution {
public:
    bool validPalindrome(string s) {
        int l = s.length();
        if (l<2) return true;
        int i=0, j=l-1;
        while (i<j && s[i]==s[j]){
            i++; j--;
        }
        return (i>=j || isPalin(s.substr(i,j-i)) ||
               isPalin(s.substr(i+1,j-i)) );
    }
    
    bool isPalin(string s){
        int l = s.length();
        for (int i=0; i<l/2; i++){
            if (s[i]!=s[l-i-1]) return false;
        }
        return true;
    }
};
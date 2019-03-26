class Solution {
public:
    int strStr(string haystack, string needle) {
        int l = needle.length();
        if (needle=="") return 0;
        else if(haystack.length()<l) return -1;
        for (int i=0; i<=haystack.length()-l; i++){
            if (match(haystack.substr(i,l),needle)){
                return i;
            }
        }
        return -1;
    }
    
    bool match(string a, string b){
        for (int i=0; i<a.length(); i++){
            if (a[i]!=b[i]) return false;
        }
        return true;
    }
};
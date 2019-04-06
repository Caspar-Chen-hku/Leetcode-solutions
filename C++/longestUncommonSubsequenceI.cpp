class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a!=b){
            return max(a.length(),b.length());
        }else{
            return -1;
        }
    }
};
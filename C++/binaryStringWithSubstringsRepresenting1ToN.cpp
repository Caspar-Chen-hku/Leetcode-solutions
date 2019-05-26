class Solution {
public:
    bool queryString(string S, int N) {
        string target;
        for (int i=N; i>=1; i--){
            if (S.find(bin(i))==-1){
                return false;
            }
        }
        return true;
    }
    
    string bin(int n){
        string s = "";
        while (n>0){
            s = to_string(n%2) + s;
            n/=2;
        }
        return s;
    }
};
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int q = 1;
        string s = A;
        while (s.length()<B.length()){
            s += A; q++;
        }
        if (s.find(B)!=string::npos){
            return q;
        }
        s += A;
        if (s.find(B)!=string::npos){
            return q+1;
        }
        return -1;
    }
};
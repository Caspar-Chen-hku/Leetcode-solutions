class Solution {
public:
    bool rotateString(string A, string B) {
        string s = A+A;
        return (A.length()==B.length() && s.find(B)!=string::npos);
    }
};
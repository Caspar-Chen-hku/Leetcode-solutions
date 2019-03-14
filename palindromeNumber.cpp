class Solution {
public:
    bool isPalindrome(int x) {
        string tocheck = to_string(x);
        int len = tocheck.length();
        for (int i=0; i<len/2; i++){
            if (tocheck[i]!=tocheck[len-1-i]) return false;
        }
        return true;
    }
};
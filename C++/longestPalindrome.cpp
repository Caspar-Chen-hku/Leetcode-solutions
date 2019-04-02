class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m;
        for (char c:s){
            m[c]++;
        }
        int result = 0;
        bool already = false;
        for (auto e:m){
            result += (e.second/2)*2;
            if (e.second%2==1 && !already){
                result++; already=true;
            }
        }
        return result;
    }
};
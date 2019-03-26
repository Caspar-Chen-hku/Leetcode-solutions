class Solution {
public:
    int titleToNumber(string s) {
       if (s.empty()) return 0;
       int result = s.back() - 'A' + 1;
        s.pop_back();
        return result + titleToNumber(s)*26;
    }
};
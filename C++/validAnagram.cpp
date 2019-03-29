class Solution {
public:
    bool isAnagram(string s, string t) {
        auto cnt = [](string& s) -> unordered_map<char, int> {
            unordered_map<char, int> cnt;
            for (auto ch:s)
                cnt[ch] ++;
            return cnt;
        };
        
        return cnt(s) == cnt(t);
    }
};
class Solution {
public:
    
    static bool compare(string& s1, string& s2){
        return (s1.length() < s2.length());
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compare);
        vector<int> chain(words.size(), 1);
        int maxlen = 1;
        for (int i=1; i<words.size(); i++){
            for (int j=0; j<i; j++){
                if (isPre(words[j], words[i])){
                    chain[i] = max(chain[i], chain[j]+1);
                }
            }
            maxlen = max(maxlen, chain[i]);
        }
        return maxlen;
    }
    
    bool isPre(string laststr, string s){
        if (s.length()!=laststr.length()+1) return false;
        bool already = false;
        for (int i=0; i<s.length(); i++){
            if (already && s[i]!=laststr[i-1]){
                return false;
            }else if (!already && (i==s.length()-1 || s[i]!=laststr[i])){
                already = true;
            }
        }
        return true;
    }
};
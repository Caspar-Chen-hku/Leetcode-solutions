class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string res = ""; int cur = 0;
        for (int i=S.length()-1; i>=0; i--){
            if (S[i]=='-') continue;
            res.push_back(toupper(S[i]));
            cur++;
            if (cur==K){
                res.push_back('-');
                cur = 0;
            }
        }
        if (res.back()=='-') res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};
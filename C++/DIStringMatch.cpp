class Solution {
public:
    vector<int> diStringMatch(string S) {
        int n = S.length();
        vector<int> perm;
        int bottom = 0, top = n;
        for (char c:S){
            if (c=='I') perm.push_back(bottom++);
            else perm.push_back(top--);
        }
        perm.push_back(top);
        return perm;
    }
};
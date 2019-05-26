class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        set<vector<int>> setVec;
        vector<int> chars;
        for (string s:A){
            chars = vector<int>(52, 0);
            for (int i=0; i<s.length(); i++){
                if (i%2){
                    chars[s[i]-'a']++;
                }else{
                    chars[s[i]-'a'+26]++;
                }
            }
            setVec.insert(chars);
        }
        return setVec.size();
    }
};
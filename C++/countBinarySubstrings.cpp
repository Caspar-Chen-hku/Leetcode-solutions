class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> groups;
        int count=1;
        for (int i=1; i<s.length(); i++){
            if (s[i]==s[i-1]){
                count++;
            }else{
                groups.push_back(count);
                count=1;
            }
        }
        groups.push_back(count);
        int res = 0;
        for (int i=0; i<groups.size()-1; i++){
            res += min(groups[i],groups[i+1]);
        }
        return res;
    }
};
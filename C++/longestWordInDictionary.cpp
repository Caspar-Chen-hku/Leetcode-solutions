class Solution {
public:
    string longestWord(vector<string>& words) {
        set<string> strs(words.begin(), words.end());
        string ans = "", temp;
        int len; bool exist = true;
        for (string s:strs){
            len = s.length();
            if (len>ans.length() || (len==ans.length() && s<ans)){
                temp = ""; exist = true;
                for (int i=0; i<len; i++){
                    temp.push_back(s[i]);
                    if (strs.find(temp)==strs.end()){
                        exist = false; break;
                    }
                }
                if (exist){
                    ans = s;
                }
            }
        }
        return ans;
    }
};
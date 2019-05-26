class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<int> maxCount(26, 0);
        vector<int> curCount;
        vector<string> res;
        bool exist = true;
        for (string b:B){
            curCount = count(b);
            for (int i=0; i<26; i++){
                maxCount[i] = max(maxCount[i], curCount[i]);
            }
        }
        for (string a:A){
            curCount = count(a); exist = true;
            for (int i=0; i<26; i++){
                if (curCount[i] < maxCount[i]){
                    exist = false; break;
                }
            }
            if (exist){
                res.push_back(a);
            }
        }
        return res;
    }
    
    vector<int> count(string s){
        vector<int> res(26, 0);
        for (char c:s){
            res[c-'a']++;
        }
        return res;
    }
};
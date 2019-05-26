class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        map<char,int> license;
        map<char,int> candidate;
        bool exist = true;
        int minLen = INT_MAX;
        string res = "";
        for (char c:licensePlate){
            if (c>='a'&&c<='z'){
                license[c]++;
            }else if (c>='A'&&c<='Z'){
                license[tolower(c)]++;
            }
        }
        for (string s:words){
            candidate.clear();
            for (char c:s){
                if (c>='a'&&c<='z'){
                    candidate[c]++;
                }else if (c>='A'&&c<='Z'){
                    candidate[tolower(c)]++;
                }
            }
            exist = true;
            for (auto e:license){
                if (e.second > candidate[e.first]){
                    exist = false; break;
                }
            }
            if (exist && s.length()<minLen){
                minLen = s.length();
                res = s;
            }
        }
        return res;
    }
};
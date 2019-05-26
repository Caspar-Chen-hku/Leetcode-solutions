class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string,int> freq;
        int maxFreq = 0;
        string maxStr;
        string curStr = "";
        for (char c:paragraph){
            if (c>='a'&&c<='z'){
                curStr.push_back(c);
            }else if (c>='A'&&c<='Z'){
                curStr.push_back(c+('a'-'A'));
            }else{
                if (!curStr.empty() && 
                    find(banned.begin(), banned.end(), curStr)==banned.end()){
                    if (++freq[curStr]>maxFreq){
                        maxFreq=freq[curStr]; maxStr = curStr;
                    }
                }
                curStr = "";
            }
        }
        if (++freq[curStr]>maxFreq){
            maxStr = curStr;
        }
        return maxStr;
    }
};
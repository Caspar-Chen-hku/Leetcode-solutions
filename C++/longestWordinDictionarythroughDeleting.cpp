class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(),d.end());
        int maxLen = 0, temp;
        string maxStr="";
        for (string str:d){
            temp = str.length();
            if (temp>maxLen && canForm(s,str)){
                maxLen = temp; maxStr = str;
            }
        }
        return maxStr;
    }
    
    bool canForm(string s, string d){
        int ls=s.length(), ld=d.length();
        int i=0, j=0;
        while (i<ls && j<ld){
            while (s[i]!=d[j] && i<ls) i++;
            if (i==ls) return false;
            i++; j++;
        }
        return (j==ld);
    }
};
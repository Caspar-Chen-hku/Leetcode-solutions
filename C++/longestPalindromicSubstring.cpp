class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n==0) return "";
        bool** palin = new bool*[n];
        for (int i=0; i<n; i++){
            palin[i] = new bool[n]();
            palin[i][i] = true;
        }
        for (int i=1; i<n; i++){
            palin[i][i-1] = true;
        }
        
        int j;
        string result = s.substr(0,1);
        for (int len=2; len<=n; len++){
            for (int i=0; i<=n-len; i++){
                j = i+len-1;
                if (palin[i+1][j-1]&&s[i]==s[j]) {
                    palin[i][j] = true;
                    result = s.substr(i,len);
                }
            }
        }
        for (int i=0; i<n; i++){
            delete[] palin[i];
        }
        delete[] palin;
        return result;
    }
};
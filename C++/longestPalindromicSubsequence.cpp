class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int l = s.length();
        int** palin = new int*[l];
        for (int i=0; i<l; i++){
            palin[i] = new int[l];
            palin[i][i] = 1;
        }
        for (int i=0; i<l-1; i++){
            if (s[i]==s[i+1]){
                palin[i][i+1] = 2;
            }else{
                palin[i][i+1] = 1;
            }
        }
        for (int len=3; len<=l; len++){
            for (int i=0; i<=l-len; i++){
                palin[i][i+len-1] = max(palin[i+1][i+len-1], palin[i][i+len-2]);
                if (s[i]==s[i+len-1]){
                    palin[i][i+len-1] = max(palin[i][i+len-1], palin[i+1][i+len-2]+2);
                }
            }
        }
        return palin[0][l-1];
    }
};
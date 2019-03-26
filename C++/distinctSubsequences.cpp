class Solution {
public:
    int numDistinct(string s, string t) {
        int ls = s.length(), lt=t.length();
        long int** num = new long int*[ls+1];
        for (int i=0; i<=ls; i++){
            num[i] = new long int[lt+1];
        }
        for (int i=0; i<=ls; i++){
            num[i][0] = 1;
        }
        for (int i=1; i<=lt; i++){
            num[0][i] = 0;
        }
        for (int i=1; i<=ls; i++){
            for (int j=1; j<=lt; j++){
                num[i][j] = num[i-1][j];
                if (s[i-1]==t[j-1]){
                    num[i][j] += num[i-1][j-1];
                }
            }
        }
        return num[ls][lt];
    }
};
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1=s1.length(), l2=s2.length(), l3=s3.length();
        if (l3!=l1+l2) return false;
        bool** result = new bool*[l1+1];
        for (int i=0; i<=l1; i++){
            result[i] = new bool[l2+1];
        }
        result[0][0] = true;
        for (int i=1; i<=l1; i++){
            result[i][0] = result[i-1][0] && s3[i-1]==s1[i-1];
        }
        for (int i=1; i<=l2; i++){
            result[0][i] = result[0][i-1] && s3[i-1]==s2[i-1];
        }
        for (int i=1; i<=l1; i++){
            for (int j=1; j<=l2; j++){
                result[i][j] =
                    (result[i-1][j] && s1[i-1]==s3[i+j-1]) ||
                    (result[i][j-1] && s2[j-1]==s3[i+j-1]);
            }
        }
        return result[l1][l2];
    }
};
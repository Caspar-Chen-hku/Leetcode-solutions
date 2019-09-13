class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length(), len2 = text2.length();
        vector<vector<int>> longest(len1+1, vector<int>(len2+1, 0));
        for (int i=1; i<=len1; i++){
            for (int j=1; j<=len2; j++){
                longest[i][j] = max(longest[i-1][j], longest[i][j-1]);
                if (text1[i-1]==text2[j-1]){
                    longest[i][j] = max(longest[i][j], longest[i-1][j-1]+1);
                }
            }
        }
        return longest[len1][len2];
    }
};
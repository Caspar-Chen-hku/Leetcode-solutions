class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int la = A.size(), lb = B.size();
        vector<vector<int>> sub(la+1, vector<int>(lb+1, 0));
        for (int i=0; i<=la; i++){
            sub[i][lb] = 0;
        }
        for (int i=0; i<lb; i++){
            sub[la][i] = 0;
        }
        int maxSub = 0;
        for (int i=la-1; i>=0; i--){
            for (int j=lb-1; j>=0; j--){
                if (A[i]==B[j]){
                    sub[i][j] = sub[i+1][j+1]+1;
                    maxSub = max(maxSub, sub[i][j]);
                }
            }
        }
        return maxSub;
    }
};
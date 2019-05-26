class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int m = A.size(), n = A[0].length();
        bool increase = true;
        int count = 0;
        for (int j=0; j<n; j++){
            increase = true;
            for (int i=1; i<m; i++){
                if (A[i][j] < A[i-1][j]){
                    increase = false;
                    break;
                }
            }
            if (!increase){
                count++;
            }
        }
        return count;
    }
};
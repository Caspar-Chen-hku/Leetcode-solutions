class Solution {
public:
    
    int check(vector<vector<int>> &A, vector<vector<int>> &B) {
        int ans = 0;
        for(int i = 0; i < A.size(); ++i) {
            for(int j = 0; j < A[0].size(); ++j) {
                int sum = 0;
                for(int k = i; k < A.size(); ++k) {
                    for(int l = j; l < A[0].size(); ++l) {
                        if(A[k][l] && A[k][l] == B[k - i][l - j]) ++sum;
                    }
                }
                ans = max(ans, sum);
            }
        }
        return ans;
    }
    
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        return max(check(A, B), check(B, A));
    }
};
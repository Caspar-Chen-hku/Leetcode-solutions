class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int l = A.size(), sum = 0, res = 0;
        vector<int> lsum(l-L+1, 0);
        vector<int> msum(l-M+1, 0);
        for (int i=0; i<max(L,M); i++){
            sum += A[i];
            if (i==L-1){
                lsum[0] = sum;
            }
            if (i==M-1){
                msum[0] = sum;
            }
        }
        for (int i=1; i<l-L+1; i++){
            lsum[i] = lsum[i-1] + A[i+L-1] - A[i-1];
        }
        for (int i=1; i<l-M+1; i++){
            msum[i] = msum[i-1] + A[i+M-1] - A[i-1];
        }
        for (int i=0; i<l-L+1; i++){
            for (int j=0; j<l-M+1; j++){
                if (j+M-1<i || i+L-1<j){
                    res = max(res, lsum[i]+msum[j]);
                }
            }
        }
        return res;
    }
};
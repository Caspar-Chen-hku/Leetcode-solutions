class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int minVal = A[0], maxVal = A[0];
        for (int i=1; i<A.size(); i++){
            minVal = min(minVal, A[i]);
            maxVal = max(maxVal, A[i]);
        }
        return max(maxVal - minVal - 2*K, 0);
    }
};
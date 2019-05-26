class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int l = A.size(), ans = A.back() - A[0], low, high;
        for (int i=0; i<l-1; i++){
            high = max(A.back()-K, A[i]+K);
            low = min(A[0]+K, A[i+1]-K);
            ans = min(ans, high- low);
        }
        return ans;
    }
};
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int N = A.size();
        vector<int> preSum(N+1, 0);
        for (int i=1; i<=N; i++){
            preSum[i] = (preSum[i-1] + A[i-1]) % K;
        }
        vector<int> count(K, 0);
        for (int i:preSum){
            count[(i+K)%K]++;
        }
        int ans = 0;
        for (int i:count){
            if (i>1){
                ans += (i-1)*i/2;   
            }
        }
        return ans;
    }
};
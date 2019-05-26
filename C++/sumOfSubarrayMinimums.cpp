class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int l = A.size(), curInd, mod = pow(10,9)+7;
        vector<int> prev(l , 0); 
        vector<int> post(l , 0);
        prev[0] = 0; post[l-1] = 0;
        for (int i=1; i<l; i++){
            if (A[i-1]<A[i]) prev[i] = 0;
            else{
                curInd = i-1;
                while (A[curInd] >= A[i]){
                    if (prev[curInd]==0) break;
                    curInd -= prev[curInd];
                }
                while (curInd > 0 && A[curInd-1]>=A[i]) curInd--;
                prev[i] = i-curInd;
            }
        }
        for (int i=l-2; i>=0; i--){
            if (A[i+1]<=A[i]) post[i] = 0;
            else{
                curInd = i+1;
                while (A[curInd] > A[i]){
                    if (post[curInd]==0) break;
                    curInd += post[curInd];
                }
                while (curInd < l-1 && A[curInd+1]>A[i]) curInd++;
                post[i] = curInd - i;
            }
        }
        int sum = 0;
        for (int i=0; i<l; i++){
            sum = (sum + (prev[i]+1)*(post[i]+1)*A[i]) % mod;
        }
        return sum;
    }
};
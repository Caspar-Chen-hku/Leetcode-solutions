class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int i = 0, l = A.size();
        while (i<l && A[i]<0 && K>0){
            A[i] = -A[i];
            i++;  K--;
        }
        if (i<l && A[i]>=0 && K%2==1){
            if (i>0 && A[i-1] < A[i]){
                A[i-1] = -A[i-1];
            }else{
                A[i] = -A[i];   
            }
        }
        int sum = 0;
        for (int a:A){
            sum += a;
        }
        return sum;
    }
};
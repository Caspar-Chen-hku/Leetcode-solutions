class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long result = 0; 
        long sum = 0;
        int n = A.size();
        for (int i=0; i<n; i++){
            result += i*A[i];
            sum += A[i];
        }
        long sol = result;
        for (int i=1; i<n; i++){
            result += sum - (long) n*A[n-i];
            sol = max(sol,result);
        }
        return sol;
    }
};
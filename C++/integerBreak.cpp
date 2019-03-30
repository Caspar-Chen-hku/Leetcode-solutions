class Solution {
public:
    int integerBreak(int n) {
        int* res = new int[n+1];
        res[0] = 0; res[1] = 1;
        for (int i=2; i<=n; i++){
            res[i] = res[i-1];
            for (int j=1; j<=i/2; j++){
                res[i] = max(res[i],(max(j,res[j])*max(i-j,res[i-j])));
            }
        }
        return res[n];
    }
};
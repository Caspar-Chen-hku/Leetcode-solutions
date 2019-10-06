class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int sign = 1;
        vector<int> res = vector<int>(n);
        res[0] = 1;
        for (int i=1; i<n; i++){
            if (k==0){
                res[i] = i+1;
            }else{
                res[i] = res[i-1] + k*sign;
                sign = -sign;
                k--;
            }
        }
        return res;
    }
};
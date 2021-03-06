class Solution {
public:
    long tomod = pow(10,9)+7;
    
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long oncemax = 0, twicemax = 0, threemax = 0;
        oncemax = calmax(1, arr);
        if (k==1) return oncemax;
        twicemax = calmax(2, arr);
        if (k==2) return twicemax;
        threemax = calmax(3, arr);
        if (threemax>twicemax){
            return (oncemax+((k-1)*(twicemax-oncemax))%tomod)%tomod;
        }else{
            return max(oncemax, twicemax)%tomod;
        }
    }
    
    long calmax(int k, vector<int>& arr){
        int res = 0;
        int m = 0;
        for (int t=0; t<k; t++){
            for (int i=0; i<arr.size(); i++){
                m = max(m+arr[i], arr[i]);
                res = max(res, m);
            } 
        }
        return res;
    }
};
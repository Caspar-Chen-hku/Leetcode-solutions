class Solution {
public:
    
    int maxTurbulenceSize(vector<int>& A) {
        int maxLen, curLen, n = A.size();
        if (n == 1) return 1;
        int compare = A[1]-A[0];
        if (compare==0){
            maxLen = curLen = 1;
        }else{
            maxLen = curLen = 2;
        }
        for (int i=1; i<n-1; i++){
            if ((A[i+1]-A[i] > 0 && compare < 0) || 
                      (A[i+1]-A[i] < 0 && compare > 0)){
                curLen++; compare = A[i+1]-A[i];
            }else{
                maxLen = max(maxLen, curLen);
                compare = A[i+1]-A[i];
                if (compare==0){
                    curLen = 1;
                }else{
                    curLen = 2;
                }
            }
        }
        return max(maxLen, curLen);
    }
};
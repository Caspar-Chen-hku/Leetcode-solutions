class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        int numWay = 0, l = A.size(), mod = pow(10,9)+7;
        int start, end, subtar;
        int left, right;
        sort(A.begin(), A.end());
        for (int i=0; i<l-2; i++){
            subtar = target-A[i];
            if (subtar<0) break;
            start = i+1; end = l-1;
            while (start<end){
                if (A[start]+A[end]==subtar){
                    if (A[start]!=A[end]){
                        left = 1; right = 1;
                        while (start+1<end && A[start+1]==A[start]){
                            left++; start++;
                        }
                        while (end-1>start && A[end-1]==A[end]){
                            right++; end--;
                        }
                        numWay = (numWay + left*right)%mod;
                        start++; end--;
                    }else{
                        numWay = (numWay + (end-start+1)*(end-start)/2)%mod;
                        break;
                    }
                }
                else if (A[start]+A[end]<subtar) start++;
                else end--;
            }
        }
        return numWay;
    }
};
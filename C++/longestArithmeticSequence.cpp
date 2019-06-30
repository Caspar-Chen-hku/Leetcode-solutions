class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int curMax = 2, l = A.size();
        for (int i=0; i<l-curMax; i++){
            for (int j=i+1; j<l-curMax; j++){
                curMax = max(curMax, 2+longest(A, j, A[j]-A[i]));
            }
        }
        return curMax;
    }
    
    int longest(vector<int>& A, int ind, int diff){
        for (int i=ind+1; i<A.size(); i++){
            if (A[i]-A[ind]==diff){
                return 1+longest(A, i, diff);
            }
        }
        return 0;
    }
};
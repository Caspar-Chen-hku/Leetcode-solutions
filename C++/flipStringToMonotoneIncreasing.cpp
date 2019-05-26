class Solution {
public:
    
    int minFlipsMonoIncr(string S) {
        int l = S.length();
        vector<int> numZeros(l+1, 0);
        numZeros[l] = 0;
        for (int i=l-1; i>=0; i--){
            numZeros[i] = numZeros[i+1] + (S[i]=='0'?1:0);
        }
        int curCost = 0, curMin = INT_MAX, numOnes = 0;
        for (int i=0; i<S.length(); i++){
            if (S[i]=='1'){
                curMin = min(curMin, curCost + numZeros[i+1]);
                curCost++; numOnes++;
            }
        }
        return min(curMin, numOnes);
    }
};
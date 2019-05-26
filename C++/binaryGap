class Solution {
public:
    int binaryGap(int N) {
        int ind = -1, maxDis = 0, curCount = 0;
        while (N>0){
            if (N%2==1){
                if (ind!=-1){
                    maxDis = max(maxDis, curCount-ind);
                }
                ind = curCount;
            }
            N /= 2; curCount++;
        }
        return maxDis;
    }
};
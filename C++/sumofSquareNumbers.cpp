class Solution {
public:
    bool judgeSquareSum(int c) {
        int i, j= (int) sqrt(c/2), s = (int) sqrt(c);
        while (j<=s){
            i = (int) sqrt(c-j*j);
            if (i*i+j*j==c) return true;
            j++;
        }
        return false;
    }
};
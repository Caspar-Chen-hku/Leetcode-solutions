class Solution {
public:
    int arrangeCoins(int n) {
        long num = 0;
        while ((num+1)*num/2<=n){
            num++;
        }
        return num-1;
    }
};
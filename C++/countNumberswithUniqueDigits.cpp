class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n==0) return 1;
        int temp = 9;
        for (int i=1; i<n; i++){
            temp *= (10-i);
        }
        return temp+countNumbersWithUniqueDigits(n-1);
    }
};
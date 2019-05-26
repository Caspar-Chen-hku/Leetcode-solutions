class Solution {
public:
    bool hasAlternatingBits(int n) {
        if (n<=2) return true;
        int last = n%2; n /= 2;
        while (n>0){
            if (n%2 + last != 1) return false;
            last = n%2; n /= 2;
        }
        return true;
    }
};
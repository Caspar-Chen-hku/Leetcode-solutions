class Solution {
public:
    bool isPerfectSquare(int num) {
        for (long i=1; i<=num; i++){
            if (i*i==num) return true;
            else if((i+1)*(i+1)>num) return false;
        }
        return false;
    }
};
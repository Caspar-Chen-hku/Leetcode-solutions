// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        return guessNum(1,n);
    }
    
    int guessNum(long i, long j){
        long mid = (i+j)/2;
        switch (guess(mid)){
            case 0: return mid; break;
            case 1: return guessNum(mid+1,j); break;
            case -1: return guessNum(i,mid-1); break;
        }
        return -1;
    }
};
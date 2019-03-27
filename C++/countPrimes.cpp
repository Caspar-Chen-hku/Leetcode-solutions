class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        for (int i=2; i<n; i++){
            if (prime(i)) count++;
        }
        return count;
    }
    
    bool prime(int n){
        for (int i=2; i<=sqrt(n); i++){
            if (n%i==0) return false;
        }
        return true;
    }
};
class Solution {
public:
    int numPrimeArrangements(int n) {
        int primes = 0;
        for (int i=2; i<=n; i++){
            if (isprime(i)){
                primes++;
            }
        }
        int todo = max(primes, n-primes);
        vector<long> fac(todo+1, 0);
        fac[0] = 1;
        int tomod = (int) pow(10,9) + 7;
        for (int i=1; i<=todo; i++){
            fac[i] = (i*fac[i-1])%tomod;
        }
        return fac[primes]*fac[n-primes]%tomod;
    }
    
    bool isprime(int n){
        for (int i=2; i<=sqrt(n); i++){
            if (n%i==0) return false;
        }
        return true;
    }
};
class Solution {
private:
    bool isPrime(int N) {
        int a = (int)sqrt((double)N);
        for (int i = 2; i <= a; i++) {
            if (N % i == 0) {
                return false;
            }
        }
        return true;
    }
public:
    int primePalindrome(int N) {
        vector<int> pp{
            2, 3, 5, 7, 11, 101, 131, 151, 181, 191, 313, 353,
            373, 383, 727, 757, 787, 797, 919, 929,
        };
        if (N < 929) {
            return *lower_bound(pp.begin(), pp.end(), N);
        }
        
        for (int i = 100; i < 1000; ++i) {
            int d0 = i / 100;
            int d1 = (i % 100) / 10;
            int n = i * 100 + d1 * 10 + d0;
            if (N > n) {
                continue;
            }
            if (isPrime(n)) {
                return n;
            }
        }
        for (int i = 1000; i < 10000; ++i) {
            int d0 = i / 1000;
            int d1 = (i % 1000) / 100;
            int d2 = (i % 100) / 10;
            int n = i * 1000 + d2 * 100 + d1 * 10 + d0;
            if (N > n) {
                continue;
            }
            if (isPrime(n)) {
                return n;
            }
        }
        for (int i = 10000; i < 20000; ++i) {
            int d0 = i / 10000;
            int d1 = (i % 10000) / 1000;
            int d2 = (i % 1000) / 100;
            int d3 = (i % 100) / 10;
            int n = i * 10000 + d3 * 1000 + d2 * 100 + d1 * 10 + d0;
            if (N > n) {
                continue;
            }
            if (isPrime(n)) {
                return n;
            }
        }
        return 0;
    }
};
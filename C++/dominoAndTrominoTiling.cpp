class Solution {
public:
    int numTilings(int n) {
      if (n == 1) return 1;
      
      long a, a_pre1 = 1, a_pre2 = 1;
      long b, b_pre1 = 1, b_pre2 = 0;
      const long mod = 1000000007;      
      
      while (--n >= 1)
      { 
        a = (a_pre1 + a_pre2 + 2*b_pre2)%mod;
        b = (a_pre1 + b_pre1)%mod;
        
        a_pre2 = a_pre1;
        a_pre1 = a;
        
        b_pre2 = b_pre1;
        b_pre1 = b;
      }
      return a;
    }
};
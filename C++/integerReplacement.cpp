class Solution {
public:
    int integerReplacement(long n) {
        int count = 0;
        while (n%2==0){
            n/=2; count++;
        }
        if (n==1) return count;
        else return count + 
            min( 1+integerReplacement(n-1),
                2+integerReplacement((n+1)/2) 
               );
    }
};
class Solution {
public:
    double myPow(double x, int n) {
        if (n==-2147483648){
            if (x==1.0){
                return 1.0;
            }else if (x>1.0){
                return 0.0;
            }
        }
        if (n<0){
            x = 1/x;
            n = -n;
        }
        if (n==1){
            return x;
        } else if (n==0){
            return 1.0;
        }
        double temp = myPow(x, n/2);
        if (n%2==0){
            return temp*temp;
        } else {
            return temp*temp*x;
        }
    }
};
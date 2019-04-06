class Solution {
public:
    bool checkPerfectNumber(int num) {
        int res = 1, temp = (int) sqrt(num);
        for (int i=2; i<=temp; i++){
            if (num%i==0){
                if (i != num/i){
                    res += i + num/i;
                }else{
                    res += i;   
                }
            }
        }
        return (num!=1 && res==num);
    }
};
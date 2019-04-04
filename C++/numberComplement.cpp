class Solution {
public:
    int findComplement(int num) {
        int res = 0, count = 0;
        while (num>0){
            res += ((num%2+1)%2)*pow(2,count);
            num /= 2;
            count++;
        }
        return res;
    }
};
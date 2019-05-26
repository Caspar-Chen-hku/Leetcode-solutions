class Solution {
public:
    int clumsy(int N) {
        int res = 0, cur = N, sign = 1;
        N--;
        char op = '*';
        while (N>0){
            if (op=='+'){
                res += cur*sign;
                cur = N; N--;
                op = '-'; sign = 1;
            }else if (op=='-'){
                res += cur*sign;
                cur = N; N--;
                op = '*'; sign = -1;
            }else if (op=='*'){
                cur *= N; N--;
                op = '/';
            }else if (op=='/'){
                cur /= N; N--;
                op = '+';
            }
        }
        return res + cur*sign;
    }
};
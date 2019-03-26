class Solution {
public:
    string convertToTitle(int n) {
        string result = "";
        if (n<=26){
            result.push_back('A'+n-1);
            return result;
        }else{
            int tail = 0;
            int divide = n;
            while (divide>0){
                tail = divide%26;
                divide = divide/26;
                if (tail==0){
                    result = "Z"+result;
                    divide--;
                }else{
                    string temp(1,'A'+tail-1);
                    result = temp + result;
                }
            }
            return result;
        }
    }
};
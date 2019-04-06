class Solution {
public:
    string convertToBase7(int num) {
        bool neg = false;
        if (num<0){
            neg=true; num = -num;
        }
        string result= "";
        while (num>0){
            result.insert(0,1,num%7+'0');
            num /= 7;
        }
        if (neg) result.insert(0,1,'-');
        return (result == "" ? "0" : result);
    }
};
class Solution {
public:
    
    string convert = "0123456789abcdef";
    
    string toHex(int num) {
        string result = "";
        unsigned int x = num;
        if (num<0) x = UINT_MAX + num + 1;
        while (x>0){
            result.insert(0,string(1,convert[x%16]));
            x /= 16;
        }
        if (result.empty()) return "0";
        else return result;
    }
};
class Solution {
public:
    string reverseStr(string s, int k) {
        int cur = 0;
        string res = "", temp;
        bool rev = true;
        while (cur<s.length()){
            temp = s.substr(cur, k);
            if (rev){
                reverse(temp.begin(), temp.end());   
            }
            res += temp; 
            rev = !rev; cur += k;
        }
        return res;
    }
};
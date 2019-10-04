class Solution {
public:
    int magicalString(int n) {
        if (n==0) return 0;
        else if (n<=3) return 1;
        string magic = "122";
        string occur = "12";
        int num = 1, cur = 1, i = 3, curoc;
        while (i<n){
            occur.push_back(magic[occur.length()]);
            curoc = occur.back()-'0';
            magic += string(curoc, cur+'0');
            if (cur==1){
                num += min(curoc, n-i);
            }
            cur = 3-cur;
            i += curoc;
        }
        return num;
    }
};
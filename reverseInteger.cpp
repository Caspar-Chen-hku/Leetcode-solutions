class Solution {
public:
    int reverse(int x) {
        vector<int> result;
        int remain;
        bool neg = false;
        if (x<0){
            x = -x;
            neg = true;
        }
        while (x>0){
            remain = x%10;
            x /= 10;
            result.push_back(remain);
        }
        int tor = 0;
        int siz = result.size();
        for (int i=0; i<siz; i++){
            tor += result[i]*pow(10,siz-1-i);
        }
        if (neg) tor = -tor;
        if ((neg&&tor>0)||(!neg&&tor<0)) return 0;
        return tor;
    }
};
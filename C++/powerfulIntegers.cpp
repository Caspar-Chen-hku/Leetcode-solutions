class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> res;
        int i=1, j=1;
        while (i+j<=bound){
            res.insert(i+j);
            while (y>1 && i+j*y<=bound){
                j*=y;
                res.insert(i+j);
            }
            if (x==1) break;
            i *= x;
            j = 1;
        }
        return vector<int>(res.begin(), res.end());
    }
};
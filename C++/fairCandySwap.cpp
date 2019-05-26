class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int totalA = 0, totalB = 0, tofind;
        set<int> aSet, bSet;
        for (int a:A){
            totalA+=a;
            aSet.insert(a);
        }
        for (int b:B){
            totalB+=b;
            bSet.insert(b);
        }
        tofind = (totalB-totalA)/2;
        for (int a:aSet){
            if (bSet.find(a+tofind)!=bSet.end()){
                return {a,a+tofind};
            }
        }
        return {};
    } 
};
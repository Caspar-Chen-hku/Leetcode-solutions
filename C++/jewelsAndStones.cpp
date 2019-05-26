class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> jewls(J.begin(), J.end());
        int num = 0;
        for (char c:S){
            if (jewls.find(c)!=jewls.end()){
                num++;
            }
        }
        return num;
    }
};
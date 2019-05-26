class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int numLine = 1, lastLine = 0, temp;
        for (char c:S){
            temp = widths[c-'a'];
            if (lastLine+temp>100){
                numLine++; lastLine = temp;
            }else{
                lastLine += temp;
            }
        }
        return {numLine, lastLine};
    }
};
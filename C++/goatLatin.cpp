class Solution {
public:
    string toGoatLatin(string S) {
        string as = "a";
        string res = "";
        string cur;
        int ind = S.find(" ");
        int lastInd = -1;
        while (ind!=string::npos){
            cur = S.substr(lastInd+1, ind-lastInd-1);
            if (cur[0]=='a' || cur[0]=='A' || cur[0]=='E' || cur[0]=='e' ||
               cur[0]=='i' || cur[0]=='I' || cur[0]=='o' || cur[0]=='O' ||
               cur[0]=='u' || cur[0]=='U'){
                cur += "ma";
            }else{
                cur.push_back(cur[0]);
                cur = cur.substr(1);
                cur += "ma";
            }
            cur+=as;
            res += cur + " ";
            as.push_back('a');
            lastInd = ind;
            ind = S.find(" ",ind+1);
        }
        cur = S.substr(lastInd+1);
        if (cur[0]=='a' || cur[0]=='A' || cur[0]=='E' || cur[0]=='e' ||
             cur[0]=='i' || cur[0]=='I' || cur[0]=='o' || cur[0]=='O' ||
             cur[0]=='u' || cur[0]=='U'){
                cur += "ma";
        }else{
                cur.push_back(cur[0]);
                cur = cur.substr(1);
                cur += "ma";
        }
        cur+=as;
        return (res+cur);
    }
};
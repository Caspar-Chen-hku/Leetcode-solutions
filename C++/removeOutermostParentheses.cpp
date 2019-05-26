class Solution {
public:
    string removeOuterParentheses(string S) {
        string res = "";
        int paren = 0, ind = 0;
        for (int i=0; i<S.length(); i++){
            if (S[i]=='('){
                paren--;
            }else{
                paren++;
            }
            if (paren==0){
                res += S.substr(ind+1, i-ind-1);
                ind = i+1;
            }
        }
        return res;
    }
};
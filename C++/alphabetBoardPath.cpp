class Solution {
public:
    string alphabetBoardPath(string target) {
        string res = a2b('a', target[0]) +"!";
        for (int i=1; i<target.length(); i++){
            res += a2b(target[i-1], target[i]) + "!";
        }
        return res;
    }
    
    string a2b(char a, char b){
        if (a==b){
            return "";
        }else if (a=='z'){
            return "U" + a2b('u', b);
        }else if (b=='z'){
            return a2b(a, 'u') + "D";
        }
        int aline = (a-'a')/5;
        int acol = (a-'a')%5;
        int bline = (b-'a')/5;
        int bcol = (b-'a')%5;
        string res = "";
        if (aline>bline){
            res += string(aline-bline, 'U');
        }else{
            res += string(bline-aline, 'D');
        }
        if (acol > bcol){
            res += string(acol-bcol, 'L');
        }else{
            res += string(bcol-acol, 'R');
        }
        return res;
    }
};
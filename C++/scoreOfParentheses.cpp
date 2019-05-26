class Solution {
public:
    int scoreOfParentheses(string S) {
        return score(S, 0, S.length()-1);
    }
    
    int score(string s, int i, int j){
        if (j==i+1) return 1;
        int balance = 0, mark = 0;
        int start = i;
        for (int ind=i; ind<=j; ind++){
            if (s[ind]=='(') balance--;
            else balance++;
            if (balance==0){
                if (ind==start+1){
                    mark += 1;
                }else{
                    mark += 2*score(s, start+1, ind-1);   
                }
                start = ind+1;
            }
        }
        return mark;
    }
};
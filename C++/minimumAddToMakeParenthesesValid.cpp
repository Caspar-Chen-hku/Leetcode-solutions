class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> paren;
        for (char c:S){
            if (c=='(') paren.push(c);
            else{
                if (!paren.empty() && paren.top()=='('){
                    paren.pop();
                }else{
                    paren.push(c);
                }
            }
        }
        return paren.size();
    }
};
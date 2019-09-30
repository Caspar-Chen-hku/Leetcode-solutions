class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> strs;
        string cur = "";
        strs.push(cur);
        for (char c:s){
            if (c=='('){
                strs.push(cur);
                cur = "";
            }else if (c==')'){
                reverse(cur.begin(), cur.end());
                cur = strs.top() + cur;
                strs.pop();
            }else{
                cur.push_back(c);
            }
        }
        return cur;
    }
};
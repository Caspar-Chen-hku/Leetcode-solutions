class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> indices;
        indices.push(-1);
        int result = 0, temp;
        for (int i=0; i<s.length(); i++){
            if (s[i]=='(') indices.push(i);
            else if(s[i]==')'){
                indices.pop();
                if (indices.empty()){
                    indices.push(i);
                }else{
                    temp = i-indices.top();
                    if (temp>result){
                        result=temp;
                    }
                }
            }
        }
        return result;
    }
};
class Solution {
public:
    int calculate(string s) {
        stack<int> res;
        int num = 0, result = 0, sign = 1;
        for (int i=0; i<s.length(); i++){
            if (s[i]>='0'){
                num = num*10 + (s[i]-'0');
            }else if(s[i]=='+'){
                result += num*sign;
                sign = 1; num=0;
            }else if (s[i]=='-'){
                result += num*sign;
                sign = -1; num=0;
            }else if (s[i]=='('){
                res.push(result);
                res.push(sign);
                result=0;
                sign=1;
            }else if (s[i]==')'){
                result += num*sign;
                sign = res.top(); res.pop();
                result = res.top()+sign*result; res.pop();
                num=0, sign=1;
            }
        }
        return result + sign*num;
    }
};
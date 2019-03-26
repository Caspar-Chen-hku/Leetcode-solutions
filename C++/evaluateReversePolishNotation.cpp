class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> result;
        int temp1, temp2;
        for (int i=0; i<tokens.size(); i++){
            if (tokens[i]=="+"||tokens[i]=="*"||
               tokens[i]=="-"||tokens[i]=="/"){
                temp2 = result.top();
                result.pop();
                temp1 = result.top();
                result.pop();
                if (tokens[i]=="+"){
                    result.push(temp1+temp2);                    
                }else if (tokens[i]=="*"){
                    result.push(temp1*temp2);
                }else if (tokens[i]=="-"){
                    result.push(temp1-temp2);
                }else{
                    result.push(temp1/temp2);
                }
            }else{
                result.push(stoi(tokens[i]));
            }
        }
        return result.top();
    }
};
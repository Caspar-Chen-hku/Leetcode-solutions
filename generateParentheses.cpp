class Solution {
public:
    vector<string> generateParenthesis(int n) {
        return backtrack("",0,0,n);
    }
    
    vector<string> backtrack(string S, int left, int right, int n){
            vector<string> result;
            vector<string> temp;
            if (S.length() == 2 * n){
                result.push_back(S);
                return result;                
            }
            if (left < n){
                temp = backtrack(S+"(", left+1, right, n);
                result.insert(result.end(),temp.begin(),temp.end());
            }
            if (right < left){
                temp = backtrack(S+")", left, right+1, n);
                result.insert(result.end(),temp.begin(),temp.end());
            }
            return result;
        }
};
class Solution {
public:
    
    vector<string> res;
    
    vector<string> letterCasePermutation(string S) {
        perm(S, 0, S.length()-1);
        return res;
    }
    
    void perm(string S, int start, int end){
        if (start>end){
            res.push_back(S); return;
        }
        char temp; bool exist = false;
        for (int i=start; i<=end; i++){
            if (S[i]>='a' && S[i]<='z'){
                exist = true;
                perm(S, i+1, end);
                temp = S[i]; S[i] += ('A'-'a');
                perm(S, i+1, end);
                S[i] = temp;
                break;
            }else if(S[i]>='A' && S[i]<='Z'){
                exist = true;
                perm(S, i+1, end);
                temp = S[i]; S[i] += ('a'-'A');
                perm(S, i+1, end);
                S[i] = temp;
                break;
            }
        }
        if (!exist){
            res.push_back(S);
        }
    }
};
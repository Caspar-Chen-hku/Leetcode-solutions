class Solution {
public:
    bool buddyStrings(string A, string B) {
        int l = A.length();
        if (l != B.length()) return false;
        vector<int> diffInd;
        set<char> chars;
        bool haveSame = false;
        for (int i=0; i<l; i++){
            if (A[i]!=B[i]){
                diffInd.push_back(i);
            }
            if (chars.find(A[i])!=chars.end()){
                haveSame = true;
            }else{
                chars.insert(A[i]);
            }
        }
        return (diffInd.empty() && haveSame) || 
            (diffInd.size()==2 && 
            A[diffInd[0]]==B[diffInd[1]] &&
            A[diffInd[1]]==B[diffInd[0]]);
    }
};
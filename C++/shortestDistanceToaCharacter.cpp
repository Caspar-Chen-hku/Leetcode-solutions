class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> charInd;
        for (int i=0; i<S.length(); i++){
            if (S[i]==C) charInd.push_back(i);
        }
        int ind = 0;
        vector<int> res;
        for (int i=0; i<S.length(); i++){
            if (ind==0){
                res.push_back(charInd[ind]-i);
            }else if (ind==charInd.size()){
                res.push_back(i-charInd.back());
            }else{
                res.push_back(min(charInd[ind]-i, i-charInd[ind-1]));
            }
            if (S[i]==C) ind++;
        }
        return res;
    }
};
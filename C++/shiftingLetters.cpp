class Solution {
public:
    
    string alphabets = "abcdefghijklmnopqrstuvwxyz";
    
    string shiftingLetters(string S, vector<int>& shifts) {
        int l = shifts.size();
        vector<int> totalShift(l, 0);
        totalShift[l-1] = shifts[l-1]%26;
        for (int i=l-2; i>=0; i--){
            totalShift[i] = (totalShift[i+1] + shifts[i])%26;
        }
        for (int i=0; i<l; i++){
            S[i] = alphabets[(S[i]-'a'+totalShift[i])%26];
        }
        return S;
    }
};
class Solution {
public:
    string reverseOnlyLetters(string S) {
        int i=0, j=S.length()-1;
        char temp;
        while (i<j){
            while (!isalpha(S[i]) && i<j) i++;
            while (!isalpha(S[j]) && i<j) j--;
            if (i<j){
                temp = S[i];
                S[i] = S[j];
                S[j] = temp;
                i++; j--;
            }
        }
        return S;
    }
};
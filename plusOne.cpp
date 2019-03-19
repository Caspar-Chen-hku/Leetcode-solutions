class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int co = 1, l=digits.size(), temp;
        for (int i=l-1; i>=0; i--){
            temp = digits[i]+co;
            digits[i] = temp%10;
            co = temp/10;
            if (co==0) break;
        }
        if (co!=0) digits.insert(digits.begin(),co);
        return digits;
    }
};
class Solution {
public:
    bool detectCapitalUse(string word) {
        int num = 0;
        for (char c:word){
            if (c<='Z') num++;
        }
        return (num==0 || num==word.length() ||
               (num==1 && word[0]<='Z'));
    }
};
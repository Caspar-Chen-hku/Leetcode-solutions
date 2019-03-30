class Solution {
public:
    string reverseVowels(string s) {
        int i=0, j=s.length()-1;
        char temp;
        while (i<j){
            if (!vowel(s[i])){
                i++; continue;
            }
            if (!vowel(s[j])){
                j--; continue;
            }
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++; j--;
        }
        return s;
    }
    
    bool vowel(char c){
        return (c=='a'||c=='A'||c=='e'||c=='E'||
                c=='i'||c=='I'||c=='o'||c=='O'||
                c=='u'||c=='U');
    }
};
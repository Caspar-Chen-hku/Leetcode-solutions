string trans[26]={".-","-...","-.-.","-..",".","..-.","--.",
                        "....","..",".---","-.-",".-..","--","-.",
                        "---",".--.","--.-",".-.","...","-","..-",
                        "...-",".--","-..-","-.--","--.."};

class Solution {
public:
    
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> strs;
        string temp;
        for (string s:words){
            temp = "";
            for (char c:s){
                temp += trans[c-'a'];
            }
            strs.insert(temp);
        }
        return strs.size();
    }
};
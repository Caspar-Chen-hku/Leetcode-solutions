class Solution {
public:
    string reverseWords(string s) {
        int ind = s.find(" "), lastind = 0;
        while (ind!=string::npos){
            reverse(s, lastind, ind-1);
            lastind = ind+1;
            ind = s.find(" ",lastind);
        }
        reverse(s, lastind, s.length()-1);
        return s;
    }
    
    void reverse(string& s, int start, int end){
        char temp;
        for (int i=start; i<=(end+start)/2; i++){
            temp = s[i];
            s[i] = s[end+start-i];
            s[end+start-i] = temp;
        }
    }
};
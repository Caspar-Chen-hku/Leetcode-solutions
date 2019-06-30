class Solution {
public:
    string removeDuplicates(string S) {
        return removeDup(S, 0);
    }
    
    string removeDup(string s, int ind){
        if (ind>=s.length()) return s;
        for (int i=ind; i<s.length()-1; i++){
            if (s[i]==s[i+1]){
                s.erase(i,2);
                return removeDup(s, max(i-1,0));
            }
        }
        return s;
    }
};
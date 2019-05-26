class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int ind = findRev(s);
        if (ind==-1) return -1;
        int ind2 = findNext(s, ind);
        char temp = s[ind];
        s[ind] = s[ind2];
        s[ind2] = temp;
        sort(s.begin()+ind+1,s.end());
        return ((s.length()==10 && s > "2147483647") ? -1 : stoi(s));
    }
    
    int findRev(string s){
        for (int i=s.length()-1; i>0; i--){
            if (s[i]>s[i-1]) return i-1;
        }
        return -1;
    }
    
    int findNext(string s, int ind){
       for (int i=ind+1; i<s.length(); i++){
            if (i==s.length()-1 || s[i+1]<=s[ind]){
                return i;
            }
        }
        return ind+1;
    }
};

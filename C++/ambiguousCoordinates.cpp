class Solution {
public:
    
    vector<string> ambiguousCoordinates(string S) {
        vector<string> s1, s2, res;
        S = S.substr(1, S.length()-2);
        for (int i=1; i<S.length(); i++){
            s1 = coords(S.substr(0, i));
            s2 = coords(S.substr(i));
            for (string r1:s1){
                for (string r2:s2){
                    res.push_back("(" + r1 + ", " + r2 + ")");
                }
            }
        }
        return res;
    }
    
    vector<string> coords(string s){
        vector<string> sol;
        if (s[0]=='0'){
            if (s=="0") return {"0"};
            else if (s.back()=='0') return {};
            else{
                s.insert(1, ".");
                return {s};
            }
        }else if (s.back()=='0'){
            return {s};
        }else{
            sol.push_back(s);
            string temp;
            for (int i=1; i<s.length(); i++){
                temp = s;
                temp.insert(i, ".");
                sol.push_back(temp);
            }
            return sol;
        }
    }
};
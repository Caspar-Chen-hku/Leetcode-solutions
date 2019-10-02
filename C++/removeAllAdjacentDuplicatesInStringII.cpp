class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<string> res;
        string cur = "";
        s.push_back(' ');
        for (char c:s){
            if (cur==""){
                cur.push_back(c);
            }else if (cur.back()==c){
                cur.push_back(c);
            }else{
                if (cur.length()<k){
                    putIn(res, cur, k);
                }else if (cur.length()>k){
                    putIn(res, string(cur.length()-k, cur[0]), k);
                }
                cur = string(1, c);
            }
        }
        string sol = "";
        while (!res.empty()){
            sol = res.top() + sol;
            res.pop();
        }
        return sol;
    }
    
    void putIn(stack<string>& res, string cur, int k){
        if (res.empty()){
            res.push(cur);
        }else{
            string t = res.top();
            if (t[0]==cur[0]){
                int l = t.length()+cur.length();
                res.pop();
                if (l>k){
                    putIn(res, string(l-k, t[0]), k);
                }else if (l<k){
                    putIn(res, cur+t, k);
                }
            }else{
                res.push(cur);
            }
        }
    }
};
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> sol;
        string cur = "";
        ipaddr(s,0,0,sol,cur);
        return sol;
    }
    
    void ipaddr(string s, int start, int num, vector<string>& sol, string& cur){
        int l = s.length();
        if (num>4) return;
        else if (start>=l){
            if (num!=4) return;
            sol.push_back(cur.substr(0,l+3));
            return;
        }
        string temp;
        int templ;
        for (int i=1; i<=l-start; i++){
            temp = s.substr(start,i);
            if (i>1 && temp[0]=='0') break;
            else if (stoi(temp)<256){
                cur += temp;
                cur.push_back('.');
                ipaddr(s, start+i, num+1, sol, cur);
                templ = cur.length();
                cur = cur.substr(0,templ-i-1);
            }else{
                break;
            }
        }
    }
};
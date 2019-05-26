class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> addresses;
        string cur = "";
        for (string e:emails){
            int i = 0; cur = "";
            while (e[i]!='@'&&e[i]!='+'){
                if (e[i]!='.'){
                    cur.push_back(e[i]);
                }
                i++;
            }
            int ind = e.find("@",i);
            cur += e.substr(ind);
            addresses.insert(cur);
        }
        return addresses.size();
    }
};
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> count;
        int space, dot, cur;
        for (string cp:cpdomains){
            space = cp.find(" ");
            cur = stoi(cp.substr(0,space));
            dot = space;
            while (dot!=string::npos){
                count[cp.substr(dot+1)] += cur;
                dot = cp.find(".",dot+1);
            }
        }
        vector<string> res;
        for (auto e:count){
            res.push_back(to_string(e.second)+" "+e.first);
        }
        return res;
    }
};
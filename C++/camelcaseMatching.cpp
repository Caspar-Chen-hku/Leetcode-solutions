class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> result;
        for (string& s:queries){
            result.push_back(match(s, pattern));
        }
        return result;
    }
    
    bool match(string query, string pattern){
        int ind = 0, l = pattern.length();
        for (int i=0; i<query.length(); i++){
            if (ind<l && query[i]==pattern[ind]){
                ind++;
            }else if (query[i]>='A' && query[i]<='Z'){
                return false;
            }
        }
        return ind==l;
    }
};
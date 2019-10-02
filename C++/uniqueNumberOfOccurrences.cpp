class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> occur;
        set<int> roccur;
        for (int a:arr){
            occur[a]++;
        }
        for (auto p:occur){
            roccur.insert(p.second);
        }
        return roccur.size()==occur.size();
    }
};
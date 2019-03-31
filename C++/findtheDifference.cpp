class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int> smap;
        map<char,int> tmap;
        
        for (char c : s){
            smap[c]++;
        }
        for (char c : t){
            tmap[c]++;
        }
        
        for (auto e:tmap){
            if (smap.count(e.first)==0 || smap[e.first] < e.second) return e.first;
        }
        return '0';
    }
};
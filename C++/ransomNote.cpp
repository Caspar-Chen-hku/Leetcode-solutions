class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> note;
        map<char,int> mag;
        
        for (char c : ransomNote){
            note[c]++;
        }
        for (char c : magazine){
            mag[c]++;
        }
        
        for (auto e:note){
            if (mag.count(e.first)==0 || mag[e.first] < e.second) return false;
        }
        return true;
    }
};
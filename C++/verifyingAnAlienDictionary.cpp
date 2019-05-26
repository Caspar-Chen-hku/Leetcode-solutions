class Solution {
public:
    
    map<char,int> mapChar;
    
    bool isAlienSorted(vector<string>& words, string order) {
        for (int i=0; i<order.size(); i++){
            mapChar[order[i]] = i;
        }
        for (int i=0; i<words.size()-1; i++){
            if (!smaller(words[i], words[i+1])) return false;
        }
        return true;
    }
    
    bool smaller(string w1, string w2){
        int l1 = w1.length(), l2 = w2.length();
        for (int i=0; i<min(l1,l2); i++){
            if (mapChar[w1[i]]>mapChar[w2[i]]) return false;
            else if (mapChar[w1[i]]<mapChar[w2[i]]) return true;
        }
        return l1<=l2;
    }
};
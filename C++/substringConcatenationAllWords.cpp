class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty()) return result;
        int l = s.length(), ws = words.size();
        int wl = words[0].length();
        int temp;
        for (int i=0; i<=l-ws*wl; i++){
            vector<string> compare = words;
            for (int j=i; j<l; j+=wl){
                temp = match(s.substr(j,wl),compare);
                if (temp==-1) break;
                else{
                    compare.erase(compare.begin()+temp);
                    if (compare.empty()){
                        result.push_back(i);
                        break;
                    }
                }
            }
        }
        return result;
        
    }
    
    int match(string s, vector<string>& words){
        for (int i=0; i<words.size(); i++){
            if (s==words[i]) return i;
        }
        return -1;
    }
};
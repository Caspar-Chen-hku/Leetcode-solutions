class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> result;
        vector<string> words = get(text);
        for (int i=0; i<words.size()-2; i++){
            if (words[i]==first && words[i+1]==second){
                result.push_back(words[i+2]);
            }
        }
        return result;
    }
    
    vector<string> get(string text){
        int ind = -1, nextind = text.find(" ");
        vector<string> result;
        while (nextind>=0){
            result.push_back(text.substr(ind+1, nextind-ind-1));
            ind = nextind;
            nextind = text.find(" ", ind+1);
        }
        result.push_back(text.substr(ind+1));
        return result;
    }
};
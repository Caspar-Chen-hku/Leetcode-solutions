class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        string result = "", temp;
        int ind, lastind=-1;
        sentence.push_back(' ');
        ind = sentence.find(" ");
        while (ind!=string::npos){
            temp = sentence.substr(lastind+1, ind-lastind-1);
            result += findRoot(dict, temp);
            lastind = ind;
            ind = sentence.find(" ",ind+1);
        }
        result.pop_back();
        return result;
    }
    
    string findRoot(vector<string>& dict, string word){
        for (string s:dict){
            if (s==word.substr(0,s.length())){
                return s+" ";
            }
        }
        return word+" ";
    }
};
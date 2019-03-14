string arr[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

class Solution {
public:
    
    vector<string> letterCombinations(string digits) {
        int len = digits.length();
        vector<string> result;
        if (len==0) return result;
        int index = digits[0]-'0';
        string target = arr[index];
        if (len==1){
            for (int i=0; i<target.length(); i++){
                result.push_back(target.substr(i,1));
            }
            return result;
        }
        string toinsert;
        vector<string> temp = letterCombinations(digits.substr(1));
        for (int i=0; i<target.length(); i++){
            for (int j=0; j<temp.size(); j++){
                toinsert = target.substr(i,1) + temp[j];
                result.push_back(toinsert);
            }
        }
        return result;
    }
};
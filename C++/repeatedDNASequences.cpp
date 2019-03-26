class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> strs;
        vector<string> result;
        if (s.length()<10) return result;
        for (int i=0; i<=s.length()-10; i++){
            string temp = s.substr(i,10);
            if (strs.count(temp)>0){
                if (strs[temp]==1){
                    result.push_back(temp);   
                }
                strs[temp]++;
            }else{
                strs[temp] = 1;
            }
        }
        return result;
    }
};
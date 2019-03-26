class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int l=strs.size();
        if (l==0){
            return "";
        }else if (l==1){
            return strs[0];
        }
        int result=0;
        int strlen = strs[0].length();
        char temp;
        for (int i=0; i<strlen; i++){
            temp = strs[0][i];
            for (int j=1; j<l; j++){
                if (i>=strs[j].length()){
                    return strs[0].substr(0,result);
                }else if(strs[j][i]!=temp){
                    return strs[0].substr(0,result);
                }
            }
            result++;
        }
        return strs[0];
    }
};
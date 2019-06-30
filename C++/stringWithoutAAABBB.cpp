class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string result = "";
        int l = 0;
        while (A>0 || B>0){
            if (l>=2 && result.back()==result[l-2]){
                if (result.back()=='a'){
                    result.push_back('b'); B--;
                }else{
                    result.push_back('a'); A--;
                }
            }else{
                if (A>B){
                    result.push_back('a'); A--;
                }else{
                    result.push_back('b'); B--;
                }
            }
            l++;
        }
        return result;
    }
};
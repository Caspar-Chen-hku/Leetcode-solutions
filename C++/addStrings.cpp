class Solution {
public:
    string addStrings(string num1, string num2) {
        int l1 = num1.length(), l2 = num2.length();
        if (l1<l2){
            num1 = string(l2-l1,'0')+num1;
        }else{
            num2 = string(l1-l2,'0')+num2;
        }
        int i = max(l1,l2)-1, out = 0, temp;
        string result(i+2,'0');
        while (i>=0){
            temp = (num1[i]-'0')+(num2[i]-'0')+out;
            result[i+1]= (temp%10)+'0';
            out = temp/10; i--;
        }
        if (out==0){
            return result.substr(1);
        }else{
            result[0] = (out+'0'); return result;    
        }
    }
};
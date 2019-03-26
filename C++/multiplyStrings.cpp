class Solution {
public:
    string multiply(string num1, string num2) {
        int l1=num1.length();
        int l2=num2.length();
        string result="0",temp;
        for (int i=l2-1; i>=0; i--){
            temp=multSingle(num1,num2[i]);
            temp = appendZeros(temp,l2-1-i);
            result = addStr(result,temp);
            cout << temp << " " << result << endl;
        }
        return removeZeros(result);
    }
    
    string removeZeros(string result){
        if (result.length()<2){
            return result;
        }else if(result[0]=='0'){
            return removeZeros(result.substr(1));
        }else{
            return result;
        }
    }
    
    string prependZeros(string num, int n){
        string result(n,'0');
        return result+num;
    }
    
    string appendZeros(string num, int n){
        string result(n,'0');
        return num+result;
    }
    
    string addStr(string n1, string n2){
        int l1=n1.length();
        int l2=n2.length();
        if (l1<l2){
            return addStr(n2,n1);
        }
        string result(l1+1,'0');
        int i=l1-1,j=l2-1,co=0,temp;
        while (j>=0){
            temp = (n1[i]-'0')+(n2[j]-'0')+co;
            result[i+1] = temp%10+'0';
            co = temp/10;
            i--;j--;
        }
        while (i>=0){
            temp = (n1[i]-'0')+co;
            result[i+1] = temp%10+'0';
            co=temp/10;
            i--;
        }
        result[0] = co+'0';
        return result;
    }
    
    string multSingle(string n1,char n2 ){
        int l = n1.length();
        string result(l+1,'0');
        int co = 0,temp;
        for (int i=l-1; i>=0; i--){
            temp = (n1[i]-'0')*(n2-'0')+co;
            result[i+1] = temp%10+'0';
            co = temp/10;
        }
        result[0] = co+'0';
        return result;
    }
    
};
class Solution {
public:
    string addBinary(string a, string b) {
        int la = a.length(), lb=b.length();
        int l = (la>lb?la:lb) + 1;
        a = addZeros(a,l-la);
        b = addZeros(b,l-lb);
        int co=0,temp;
        string result(l,'0');
        for (int i=l-1; i>=0; i--){
            temp = (a[i]-'0')+(b[i]-'0')+co;
            result[i]= temp%2 + '0';
            co = temp/2;
        }
        if (result[0]=='0') return result.substr(1);
        else return result;
    }
    
    string addZeros(string a, int num){
        string temp(num,'0');
        return temp+a;
    }
};
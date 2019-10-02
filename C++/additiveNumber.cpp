class Solution {
public:
    bool isAdditiveNumber(string num) {
        long n1 = 0, n2 = 0;
        for (int i=1; i<=num.length()/2; i++){
            if (i>1 && num[0]=='0') break;
            n1 = n1*10 + (num[i-1]-'0'); n2 = 0;
            for (int j=1; j<=num.length()-2*i; j++){
                if (j>1 && num[i]=='0') break;
                else if (i+j>=num.length()) break;
                n2 = n2*10 + (num[i+j-1]-'0');
                if (additive(num.substr(i+j), n1, n2)) return true;
                else if (n2>=LONG_MAX/10) break;
            }
        }
        return false;
    }
    
    bool additive(string num, long n1, long n2){
        if (num.empty()) return true;
        else if (num[0]-'0'==n1+n2) return additive(num.substr(1), n2, num[0]-'0');
        else if (num[0]=='0') return false;
        long cur = 0;
        for (int i=0; i<num.length(); i++){
            cur = cur*10 + (num[i]-'0');
            if (cur==n1+n2){
                return additive(num.substr(i+1), n2, cur);
            }else if (cur>n1+n2) return false;
        }
        return false;
    }
};
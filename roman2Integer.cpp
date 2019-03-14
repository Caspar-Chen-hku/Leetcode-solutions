class Solution {
public:
    int romanToInt(string s) {
        int l = s.length();
        if (l==0){
            return 0;
        }else if(l==1){
            return match(s[0]);
        }else{
            string temp = s.substr(0,2);
            string rest = s.substr(1);
            if (temp=="IV"||temp=="IX"){
                return romanToInt(rest)-1;
            }else if(temp=="XL"||temp=="XC"){
                return romanToInt(rest)-10;
            }else if(temp=="CD"||temp=="CM"){
                return romanToInt(rest)-100;
            }else{
                return match(s[0])+romanToInt(rest);
            }
        }
    }
    
    int match(char c){
        switch(c) {
            case 'I': return 1; break;
            case 'V': return 5; break;
            case 'X': return 10; break;
            case 'L': return 50; break;
            case 'C': return 100; break;
            case 'D': return 500; break;
            case 'M': return 1000; break;
            default: return -1; break;
        }
    }
};
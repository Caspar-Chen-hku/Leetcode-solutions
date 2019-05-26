class Solution {
public:
    string fractionAddition(string expression) {
        pair<int,int> res = make_pair(0,1);
        pair<int,int> cur = make_pair(0,0);
        int num = 0, sign = 1;
        expression.push_back('+');
        for (char c:expression){
            if (c=='+' || c=='-'){
                cur.second = num;
                num = 0;
                res = add(res, cur, sign);
                sign = (c=='+'?1:-1); 
            }else if (c=='/'){
                cur.first = num;
                num=0;
            }else{
                num = num*10 + (c-'0');
            }
        }
        bool pos = (res.first * res.second >= 0);
        
        return (pos ? "" : "-") +  to_string(abs(res.first)) + "/" 
            + to_string(abs(res.second));
    }
    
    pair<int,int> add(pair<int,int> a, pair<int,int> b, int sign){
        pair<int,int> res;
        res.second = a.second * b.second;
        res.first = a.first*b.second + sign*a.second*b.first;
        int temp = gcd(res.first, res.second);
        if (temp==0) {
            res.second = 1;
            return res;
        }
        res.first /= temp;
        res.second /= temp;
        return res;
    }
    
    int gcd(int a, int b) { 
        if (b == 0) return a; 
        return gcd(b, a % b);  
    } 
};
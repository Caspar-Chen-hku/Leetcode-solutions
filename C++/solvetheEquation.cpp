class Solution {
public:
    string solveEquation(string equation) {
        int sign = equation.find("=");
        equation.push_back('+');
        pair<int,int> left = simplify(equation.substr(0,sign+1));
        pair<int,int> right = simplify(equation.substr(sign+1));
        if (left==right){
            return "Infinite solutions";
        }else if (left.first==right.first && left.second!=right.second){
            return "No solution";
        }else{
            int res = (right.second-left.second)/(left.first-right.first);
            return "x=" + to_string(res);
        }
    }
    
    //<num_x, const>
    pair<int,int> simplify(string e){
        pair<int,int> res = make_pair(0,0);
        int num = 0, x = 0, sign = 1;
        char c;
        for (int i=0; i<e.length(); i++){
            c = e[i];
            if (c=='+'||c=='-'||c=='='){
                res.first += x*sign;
                res.second += num*sign;
                x = 0, num = 0;
                sign = (c=='+'?1:-1);
            }else if (c=='x'){
                if (num==0 && (i==0 || e[i-1]=='+' || e[i-1]=='-')){
                    x++;
                }else{
                    x += num; num=0;
                }
            }else{
                num = num*10 + (c-'0');
            }
        }
        return res;
    }
};
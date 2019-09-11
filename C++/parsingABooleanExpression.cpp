class Solution {
public:
    bool parseBoolExpr(string e) {
        if (e[0]=='t' || e[0]=='f'){
            return e=="t";
        }else if (e[0]=='!'){
           return !parseBoolExpr(e.substr(2, e.length()-3));
        }else if (e[0]=='&'){
            int cur = 2; bool res = true; int len;
            while (cur < e.length()){
                len = curStr(e, cur);
                res = res && parseBoolExpr(e.substr(cur,len));
                cur += len+1;
            }
            return res;
        }else if (e[0]=='|'){
            int cur = 2;
            bool res = false; int len;
            while (cur < e.length()){
                len = curStr(e, cur);
                res = res || parseBoolExpr(e.substr(cur, len));
                cur+=len+1;
            }
            return res;
        }else{
            cout << e;
            return false;
        }
    }
    
    int curStr(string e, int cur){
        if (e[cur]=='t' || e[cur]=='f'){
            return 1;
        }else{
            int num = 0;
            for (int i=cur+1; i<e.length(); i++){
                if (e[i]=='(') num++;
                else if (e[i]==')'){
                    num--;
                    if (num==0) return i-cur+1;
                }
            }
            return -1;
        }
    }
        
};
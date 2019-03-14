class Solution {
public:
    
    void removeSpace(string& str){
        while (str[0]==' ') str.erase(0,1);
    }
    
    int myAtoi(string str) {
        vector<int> num;
        removeSpace(str);
        
        bool pos;
        if (str[0]=='-') {
            pos=false;
            str.erase(0,1);
        }
        else if (str[0]=='+'){
            pos=true;
            str.erase(0,1);
        }else if(str[0]>='0'&&str[0]<='9') {
            pos=true;
        }
        else return 0;
        
        int temp;
        for (int i=0; i<str.length(); i++){
            temp = str[i]-'0';
            if (temp<0||temp>9) break;
            else if (temp==0&&num.empty()) continue;
            num.push_back(temp);
        }
        
        int result = 0;
        int siz = num.size();
        for (int i=0; i<siz; i++){
            result += num[i]*pow(10,siz-1-i);
        }
        if (!pos) result = -result;
        cout << result << endl;
        if ((result>0||siz>10)&&!pos){
            return -2147483648;
        }else if((result<0||siz>10)&&pos){
           return  2147483647;
        } 
        else return result;
    }
};
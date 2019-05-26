class Solution {
public:
    int maximumSwap(int num) {
        return stoi(maxSwap(to_string(num)));
    }
    
    string maxSwap(string num){
        int l = num.length();
        if (l<2) return num;
        int largest = num[0]-'0', ind = 0;
        for (int i=1; i<l; i++){
            if (num[i]-'0'>=largest){
                largest = num[i]-'0'; ind = i;
            }
        }
        if (ind>0 && largest!=num[0]-'0'){
            char temp = num[0];
            num[0] = num[ind];
            num[ind] = temp;
            return num;
        }else{
            return num.substr(0,1) + maxSwap(num.substr(1));
        }
    }
};
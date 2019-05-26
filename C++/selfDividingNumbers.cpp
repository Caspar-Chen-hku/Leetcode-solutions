class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        int copy, temp;
        bool exist = true;
        for (int n=left; n<=right; n++){
            copy = n; exist = true;
            while(copy>0){
                temp = copy%10;
                copy /= 10;
                if (temp==0 || n%temp!=0){
                    exist = false; break;
                }
            }
            if (exist){
                res.push_back(n);
            }
        }
        return res;
    }
};
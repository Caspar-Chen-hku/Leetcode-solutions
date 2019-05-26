class Solution {
public:
    int rotatedDigits(int N) {
        int num = 0;
        for (int i=2; i<=N; i++){
            if (valid(i)) num++;
        }
        return num;
    }
    
    bool valid(int n){
        int temp; 
        bool same = true;
        while (n>0){
            temp = n%10;
            n /= 10;
            if (temp==3 || temp==4 || temp==7) return false;
            else if (temp==2 || temp==5 || temp==6 || temp==9){
                same = false;
            }
        }
        return (!same);
    }
};
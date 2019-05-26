class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int res = 0, temp;
        for (int i=L; i<=R; i++){
            temp = countBits(i);
            if (temp==2 || temp==3 || temp==5 || temp==7 || temp==11
               || temp==13 || temp==17 || temp==19){
                res++;
            }
        }
        return res;
    }
    
    int countBits(int target){
        int res = 0;
        while (target>0){
            res += target%2;
            target /= 2;
        }
        return res;
    }
};
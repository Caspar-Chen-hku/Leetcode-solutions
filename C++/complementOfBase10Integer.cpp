class Solution {
public:
    int bitwiseComplement(int N) {
        int num=2;
        while (num<=N){
            num*=2;
        }
        return num-1-N;
    }
};
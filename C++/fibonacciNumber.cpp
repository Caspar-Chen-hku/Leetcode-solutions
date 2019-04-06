class Solution {
public:
    int fib(int N) {
        if (N==0) return 0;
        int* seq = new int[N+1];
        seq[0] = 0; seq[1] = 1;
        for (int i=2; i<=N; i++){
            seq[i] = seq[i-1] + seq[i-2];
        }
        return seq[N];
    }
};
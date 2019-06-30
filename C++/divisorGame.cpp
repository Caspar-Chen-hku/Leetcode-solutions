class Solution {
public:
    bool divisorGame(int N) {
        vector<bool> play(N+1, false);
        for (int i=1; i<=N; i++){
            for (int j=1; j<i; j++){
                if (i%j==0 && !play[i-j]){
                    play[i] = true; break;
                }
            }
        }
        return play[N];
    }
};
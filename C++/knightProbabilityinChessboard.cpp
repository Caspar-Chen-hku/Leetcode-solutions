class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        double*** prob = new double**[N];
        for (int i=0; i<N; i++){
            prob[i] = new double*[N];
            for (int j=0; j<N; j++){
                prob[i][j] = new double[2];
                prob[i][j][0] = (i==r&&j==c ? 1 : 0);
            }
        }
        int step = 0;
        for (int count = 1; count<=K; count++){
            step = (step+1)%2;
            for (int i=0; i<N; i++){
                for (int j=0; j<N; j++){
                    prob[i][j][step] = compute(N, prob, i, j, (step+1)%2);
                }
            }
        }
        double res = 0;
        for (int i=0; i<N; i++){
            for (int j=0; j<N; j++){
                res += prob[i][j][K%2];
            }
        }
        return res;
    }
    
    double compute(int N, double*** prob, int i, int j, int step){
        double sum = 0;
        if (i-2>=0 && j-1>=0){
            sum += prob[i-2][j-1][step];
        }
        if (i-1>=0 && j-2>=0){
            sum += prob[i-1][j-2][step];
        }
        if (i+1<N && j-2>=0){
            sum += prob[i+1][j-2][step];
        }
        if (i+2<N && j-1>=0){
            sum += prob[i+2][j-1][step];
        }
        if (i+2<N && j+1<N){
            sum += prob[i+2][j+1][step];
        }
        if (i+1<N && j+2<N){
            sum += prob[i+1][j+2][step];
        }
        if (i-1>=0 && j+2<N){
            sum += prob[i-1][j+2][step];
        }
        if (i-2>=0 && j+1<N){
            sum += prob[i-2][j+1][step];
        }
        return sum/8;
    }
};
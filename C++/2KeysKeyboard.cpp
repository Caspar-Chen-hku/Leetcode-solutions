class Solution {
public:
    int minSteps(int n) {
       int* step = new int[n+1];
        step[0] = step[1] = 0;
        int temp;
        for (int i=2; i<=n; i++){
            step[i] = i; temp = (int) sqrt(i);
            for (int j=2; j<=temp; j++){
                if (i%j==0){
                    step[i] = min(step[i], min(step[j]+i/j,step[i/j]+j));
                }
            }
        }
        return step[n];
    }
};
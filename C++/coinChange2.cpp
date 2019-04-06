class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int l = coins.size();
        int** kinds = new int*[l+1];
        for (int i=0; i<=l; i++){
            kinds[i] = new int[amount+1];
            kinds[i][0] = 1;
        }
        for (int i=1; i<=amount; i++){
            kinds[0][i] = 0;
        }
        for (int i=1; i<=l; i++){
            for (int j=1; j<=amount; j++){
                kinds[i][j] = kinds[i-1][j];
                for (int k=1; k<=j/coins[i-1]; k++){
                    kinds[i][j] += kinds[i-1][j-k*coins[i-1]];
                }
            }
        }
        return kinds[l][amount];
    }
};
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int l = coins.size();
        int** sol = new int*[l+1];
        for (int i=0; i<=l; i++){
            sol[i] = new int[amount+1];
            sol[i][0] = 0;
        }
        for (int i=1; i<=amount; i++){
            sol[0][i] = INT_MAX;
        }
        for (int i=1; i<=l; i++){
            for (int j=1; j<=amount; j++){
                sol[i][j] = sol[i-1][j];
                for (int k=1; k*coins[i-1]<=j; k++){
                    if (sol[i-1][j-k*coins[i-1]]==INT_MAX) continue;
                    sol[i][j] = min(sol[i][j], sol[i-1][j-k*coins[i-1]]+ k);
                }
            }
        }
        return (sol[l][amount] == INT_MAX ? -1 : sol[l][amount]);
    }
};
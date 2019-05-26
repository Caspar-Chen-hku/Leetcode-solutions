class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int l = piles.size();
        vector<vector<int>> score(l, vector<int>(l, 0));
        for (int i=0; i<l; i++){
            score[i][i] = piles[i];
        }
        for (int len=1; len<l; len++){
            for (int i=0; i<l-len; i++){
                if (len%2==1){
                    score[i][i+len] = max(score[i][i+len-1] + piles[i+len], 
                                         score[i+1][i+len] + piles[i]);
                }else{
                    score[i][i+len] = max(score[i][i+len-1] - piles[i+len], 
                                         score[i+1][i+len] - piles[i]);
                }
            }
        }
        return (score[0][l-1]>0);
    }
};
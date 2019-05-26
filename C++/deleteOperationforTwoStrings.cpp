class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();
        int** steps = new int*[l1+1];
        for (int i=0; i<=l1; i++){
            steps[i] = new int[l2+1];
            steps[i][0] = i;
        }
        for (int i=1; i<=l2; i++){
            steps[0][i] = i;
        }
        for (int i=1; i<=l1; i++){
            for (int j=1; j<=l2; j++){
                if (word1[i-1]==word2[j-1]){
                    steps[i][j] = steps[i-1][j-1];
                }else{
                    steps[i][j] = min(steps[i][j-1],steps[i-1][j])+1;
                }
            }
        }
        return steps[l1][l2];
    }
};
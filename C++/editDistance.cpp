class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1=word1.length(), l2=word2.length();
        int** dis = new int*[l1+1];
        for (int i=0; i<=l1; i++){
            dis[i] = new int[l2+1];
        }
        for (int i=0; i<=l1; i++){
            dis[i][0] = i;
        }
        for (int i=0; i<=l2; i++){
            dis[0][i] = i;
        }
        for (int i=1; i<=l1; i++){
            for (int j=1; j<=l2; j++){
                if (word1[i-1]==word2[j-1]){
                    dis[i][j] = min(dis[i-1][j-1],dis[i-1][j]+1,dis[i][j-1]+1);
                }else{
                    dis[i][j] = min(dis[i-1][j-1]+1,dis[i-1][j]+1,dis[i][j-1]+1);
                }
            }
        }
        return dis[l1][l2];
    }
    
    int min(int a,int b,int c){
        if (a<b){
            return (a<c?a:c);
        }else{
            return (b<c?b:c);
        }
    }
};
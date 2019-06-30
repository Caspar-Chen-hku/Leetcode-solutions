class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int dp[50][50];
        memset(dp,0,sizeof(dp));
        int numofnode = A.size();
        for(int len=3; len<=numofnode; len++)
            for(int i=0; i+len-1<numofnode; i++)
            {
                int j=i+len-1;
                dp[i][j]=INT_MAX;
                for(int k=i+1; k<j; k++)
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]+A[i]*A[j]*A[k]);
            }
        return dp[0][A.size()-1];        
    }
};
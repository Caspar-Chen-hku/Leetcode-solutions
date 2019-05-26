class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int maxscore = 0, prev = A[0];
        for (int j=1; j<A.size(); j++){
            maxscore = max(maxscore, prev+A[j]-j);
            prev = max(prev, A[j]+j);
        }
        return maxscore;
    }
};
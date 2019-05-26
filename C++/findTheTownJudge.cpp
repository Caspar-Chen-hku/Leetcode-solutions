class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> numTrust(N, 0);
        vector<int> numBeTrust(N, 0);
        for (vector<int> v:trust){
            numTrust[v[0]-1]++;
            numBeTrust[v[1]-1]++;
        }
        for (int i=0; i<N; i++){
            if (numTrust[i]==0 && numBeTrust[i]==N-1){
                return i+1;
            }
        }
        return -1;
    }
};
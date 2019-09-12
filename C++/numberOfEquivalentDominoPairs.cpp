class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int numPair = 0;
        map<pair<int,int>,int> dom;
        for (auto p:dominoes){
            dom[{min(p[0],p[1]), max(p[0],p[1])}]++;
        }
        for (auto p:dom){
            numPair += p.second*(p.second-1)/2;
        }
        return numPair;
    }
};
class Solution {
public:
    vector<int> partitionLabels(string S) {
        map<char, int> lastOccur;
        for (int i=S.length()-1; i>=0; i--){
            if (lastOccur.count(S[i])==0){
                lastOccur[S[i]] = i;
            }
        }
        int start = 0, end;
        vector<int> res;
        while (start<S.length()){
            end = lastOccur[S[start]];
            for (int i=start; i<=end; i++){
                end = max(end, lastOccur[S[i]]);
            }
            res.push_back(end-start+1);
            start = end+1;
        }
        return res;
    }
};
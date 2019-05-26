class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> uncommon;
        map<string, int> strs;
        int lastInd = -1, ind = A.find(" ");
        while (ind!=string::npos){
            strs[A.substr(lastInd+1, ind-lastInd-1)]++;
            lastInd = ind; ind = A.find(" ", ind+1);
        }
        strs[A.substr(lastInd+1)]++;
        lastInd = -1; ind = B.find(" ");
        while (ind!=string::npos){
            strs[B.substr(lastInd+1, ind-lastInd-1)]++;
            lastInd = ind; ind = B.find(" ", ind+1);
        }
        strs[B.substr(lastInd+1)]++;
        for (auto e:strs){
            if (e.second==1){
                uncommon.push_back(e.first);
            }
        }
        return uncommon;
    }
};
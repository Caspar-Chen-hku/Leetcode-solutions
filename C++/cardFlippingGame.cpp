class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        set<int> dup;
        int temp1, temp2, res=INT_MAX;
        for (int i=0; i<fronts.size(); i++){
            if (fronts[i]==backs[i]){
                dup.insert(fronts[i]);
            }
        }
        for (int i=0; i<fronts.size(); i++){
            if (fronts[i]!=backs[i]){
                temp1 = min(fronts[i],backs[i]);
                temp2 = max(fronts[i],backs[i]);
                if (temp1<res && dup.find(temp1)==dup.end()){
                       res = temp1;
                }else if (temp2<res && dup.find(temp2)==dup.end()){
                       res = temp2;
                }
            }
        }
        return (res == INT_MAX ? 0 : res);
    }
};
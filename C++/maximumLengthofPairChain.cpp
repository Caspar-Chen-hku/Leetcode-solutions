class Solution {
public:
    
    static bool compare(vector<int> a, vector<int> b){
        return a[1]<b[1];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), compare);
        int i=0, num=0;
        bool exist = false;
        while (i<pairs.size()){
            num++; exist=false;
            for (int j=i+1; j<pairs.size(); j++){
                if (pairs[j][0]>pairs[i][1]){
                    i=j; exist=true; break;
                }
            }
            if (!exist) break;
        }
        return num;
    }
};
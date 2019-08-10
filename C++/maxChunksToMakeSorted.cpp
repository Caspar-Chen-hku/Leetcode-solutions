class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0, cur = 0;
        for (int i=0; i<arr.size(); i++){
            cur = max(cur, arr[i]);
            if (i==cur){
                res++;
            }
        }
        return res;
    }
};
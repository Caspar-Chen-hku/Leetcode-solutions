class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = 0, right = 0, mid;
        for (int w:weights){
            left = max(left, w);
            right += w;
        }
        int need, cur;
        while (left<right){
            mid = (left+right)/2;
            need = 1; cur = 0;
            for (int w:weights){
                if (cur+w>mid){
                    need++; cur=w;
                }else{
                    cur+=w;
                }
            }
            if (need>D){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return left;
    }
};
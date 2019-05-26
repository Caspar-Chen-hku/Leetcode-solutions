class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int l = nums.size();
        if (l==0) return -1;
        else if (l==1) return 0;
        int* lsum = new int[l];
        int* rsum = new int[l];
        lsum[0] = nums[0], rsum[l-1] = nums[l-1];
        for (int i=1; i<l; i++){
            lsum[i] = lsum[i-1]+nums[i];
        }
        for (int i=l-2; i>=0; i--){
            rsum[i] = rsum[i+1]+nums[i];
        }
        if (rsum[1]==0) return 0;
        for (int i=1; i<l-1; i++){
            if (rsum[i+1]==lsum[i-1]) return i;
        }
        if (lsum[l-2]==0) return l-1;
        else return -1;
    }
};
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int l = nums.size();
        if (l==1) return 0;
        int maxInd, maxNum, nextLarge;
        if (nums[0]>nums[1]){
            maxInd = 0; maxNum = nums[0]; nextLarge = nums[1];
        }else{
            maxInd = 1; maxNum = nums[1]; nextLarge = nums[0];
        }
        for (int i=2; i<l; i++){
            if (nums[i]>maxNum){
                nextLarge = maxNum;
                maxNum = nums[i];
                maxInd = i;
            }else if (nums[i]>nextLarge){
                nextLarge = nums[i];
            }
        }
        if (maxNum>=2*nextLarge){
            return maxInd;
        }else{
            return -1;
        }
    }
};
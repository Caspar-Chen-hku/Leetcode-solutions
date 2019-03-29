class Solution {
public:
    int numSquares(int n) {        
        int* nums = new int[n+1];
        nums[0] = 0;
        for (int i=1; i<=n; i++){
            nums[i] = nums[i-1]+1;
            for (int j=1; j<=sqrt(i); j++){
                nums[i] = min(nums[i], nums[i-j*j]+1);
            }
        }
        return nums[n];
    }   
};
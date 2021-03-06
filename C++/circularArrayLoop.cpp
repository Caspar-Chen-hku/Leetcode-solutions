class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++){
            if (nums[i]==0) continue;
            int j = i;
            int k = next(nums, i);
            while (nums[k]*nums[i]>0 && nums[next(nums,k)]*nums[i]>0){
                if (j==k){
                    if (j!=next(nums,j)) return true;
                    else break;
                }
                j = next(nums,j);
                k = next(nums,next(nums,k));
            }
            j = i;
            while (nums[j]*nums[i]>0){
                nums[j] = 0;
                j = next(nums,j);
            }
        }
        return false;
    }
    
    int next(vector<int>& nums, int ind){
        int res = (ind + nums[ind]);
        while (res<0) res += nums.size();
        while (res>=nums.size()) res -= nums.size();
        return res;
    }
};
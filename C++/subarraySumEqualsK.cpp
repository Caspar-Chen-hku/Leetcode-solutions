class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        int l = nums.size();
        int* sum = new int[l];
        sum[0] = nums[0];
        for (int i=1; i<l; i++){
            sum[i] = sum[i-1] + nums[i];
        }
        int temp, count = 0;
        for (int j=0; j<l; j++){
            temp = sum[j];
            if (temp==k) count++;
            for (int i=0; i<j; i++){
                temp -= nums[i];
                if (temp==k) count++;
            }
        }
        return count;
    }
};
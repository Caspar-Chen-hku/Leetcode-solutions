class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = 10000;
        int n = nums.size();
        int sum;
        for (int i=0; i<n-2; i++){
            sum = nums[i];
            for (int j=i+1; j<n-1; j++){
                sum += nums[j];
                for (int k=j+1; k<n; k++){
                    sum += nums[k];
                    if (abs(sum-target)<abs(closest-target)){
                        closest = sum;
                    }
                    sum -= nums[k];
                }
                sum -= nums[j];
            }
        }
        return closest;
    }
};
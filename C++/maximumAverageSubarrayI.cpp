class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        for (int i=0; i<k; i++){
            sum += nums[i];
        }
        double maxsum = sum;
        for (int i=k; i<nums.size(); i++){
            sum += nums[i]-nums[i-k];
            maxsum = max(maxsum, sum);
        }
        return maxsum/k; 
    }
};
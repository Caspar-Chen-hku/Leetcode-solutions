class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxcons = 0, cur = 0;
        for (int n:nums){
            if (n==1) cur++;
            else{
                maxcons = max(maxcons, cur);
                cur = 0;
            }
        }
        return max(maxcons, cur);
    }
};
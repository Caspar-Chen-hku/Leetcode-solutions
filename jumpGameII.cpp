class Solution {
public:
    int jump(vector<int>& nums) {

        int m = 0, jump = 1, l = 0, i = 0;
        int n = nums.size();
        if(n==1) return 0;
        
        while(m + nums[m] < n-1){
            while(i<n && i <= l + nums[l]){
                if(i + nums[i] > m + nums[m]) m = i;
                i++;
            }
            jump++;
            l = m;
        }
        return jump;
    }
};
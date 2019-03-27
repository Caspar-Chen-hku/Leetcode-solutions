class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        else if (nums.size()==1) return nums[0];
        int temp = nums.back();
        nums.pop_back();
        
        int m1 = robRemoved(nums);
        
        nums.push_back(temp);
        nums.erase(nums.begin());
        
        int m2 = robRemoved(nums);
        return max(m1,m2);
    }
    
    int robRemoved(vector<int>& nums){
        int* maxnum = new int[nums.size()+1];
        maxnum[0] = 0; maxnum[1] = nums[0];
        for (int i=2; i<=nums.size(); i++){
            maxnum[i] = max(nums[i-1]+maxnum[i-2],maxnum[i-1]);
        }
        return maxnum[nums.size()];
    }
    
};
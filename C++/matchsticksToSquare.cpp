class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int total=0;
        if(nums.size()<4) return false;
        for(auto & nn:nums)
            total += nn;
        if((total&3)!=0) return false;
        total=total/4;
        sort(nums.begin(),nums.end(),greater<int>());
        
        bool ret=false;
        for(int i=0;i<3;i++){
            if(!dfs(nums, total))
                return ret;
        }
        return true;
    }
    
    bool dfs(vector<int>& nums, int total) {
        if(total==0) return true;
        else if(total<0) return false;
        int i=0;
        while(i+1<nums.size() && nums[i]<0) i++;
        if(i==nums.size()-1 && (nums[i]<total)) return false;
        int t=nums[i];
        nums[i]=-1;
        if(dfs(nums, total-t))
            return true;
        if(dfs(nums, total)){
            nums[i]=t;
            return true;
        }
        else {
            nums[i]=t;
            return false;
        }
        
    }
};
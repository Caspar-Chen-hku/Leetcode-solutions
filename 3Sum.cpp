class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> result;
        int l = nums.size();
        int target,start,end,temp;
        vector<int> middle;
        
        for (int i=0; i<l-2; i++){
            if (nums[i]>0){
                break;
            }else if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            target = -nums[i];
            start=i+1; end=l-1;
            while (start<end){
                temp = nums[start]+nums[end];
                if ((start>i+1&&nums[start]==nums[start-1]) || temp<target) {
                    start++;
                }else if((end<l-1&&nums[end]==nums[end+1]) || temp>target){
                    end--;
                }else{
                    middle.clear();
                    middle.push_back(nums[i]);
                    middle.push_back(nums[start]);
                    middle.push_back(nums[end]);
                    result.push_back(middle);
                    start++;
                    end--;
                }
            }
        }
        
        return result;        
    }
};
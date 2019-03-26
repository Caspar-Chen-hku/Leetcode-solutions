class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > result;
        vector<int> toinsert;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        int sum;
        for (int i=0; i<n-3; i++){
            if (i>0&&nums[i]==nums[i-1]) continue;
            sum = nums[i];
            for (int j=i+1; j<n-2; j++){
                if (j>i+1&&nums[j]==nums[j-1]) continue;
                sum += nums[j];
                for (int m=j+1; m<n-1; m++){
                    if (m>j+1&&nums[m]==nums[m-1]) continue;
                    sum += nums[m];
                    for (int k=m+1; k<n; k++){
                        sum += nums[k];
                        if (sum==target){
                            toinsert.push_back(nums[i]);
                            toinsert.push_back(nums[j]);
                            toinsert.push_back(nums[m]);
                            toinsert.push_back(nums[k]);
                            result.push_back(toinsert);
                            toinsert.clear();
                            sum -= nums[k];
                            break;
                        }
                        sum -= nums[k];
                    }
                    sum -= nums[m];
                }
                sum -= nums[j];
            }
        }
        
        return result;
    }
};
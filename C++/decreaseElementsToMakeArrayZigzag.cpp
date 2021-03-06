class Solution {
public:
    static int firstSeq(vector<int> &nums) {
        int last_num = nums[0], res = 0, n = nums.size();
        
        for(int i = 1; i < n; ++i) {
            if(i % 2 == 1 && nums[i] >= last_num) {
                res += (nums[i] - last_num + 1);
                --last_num;
            }
            
            else if(i % 2 == 0 && nums[i] <= last_num) {
                res += (last_num - nums[i] + 1);
                last_num = nums[i];
            }
            
            else
                last_num = nums[i];
        }
        
        return res;
    }
    
    
    static int secondSeq(vector<int> &nums) {
        int last_num = nums[0], res = 0, n = nums.size();
        
        for(int i = 1; i < n; ++i) {
            if(i % 2 == 1 && nums[i] <= last_num) {
                res += (last_num - nums[i] + 1);
                last_num = nums[i];
            }
            
            else if(i % 2 == 0 && nums[i] >= last_num) {
                res += (nums[i] - last_num + 1);
                --last_num;;
            }
            
            else
                last_num = nums[i];
        }
        
        return res;
    }
    
    int movesToMakeZigzag(vector<int>& nums) {
        int res_f = firstSeq(nums);
        int res_s = secondSeq(nums);
        
        return(min(res_f, res_s));
    }
};
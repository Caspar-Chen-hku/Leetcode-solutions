class Solution {
public:
    bool isPossible(vector<int>& nums) {
        if (nums.empty()) return false;
        int start = nums[0];
        vector<int> counts(nums.back() - start + 1);
        for(int num : nums) {
            counts[num - start]++;
        }
        int i = 0;
        while (i < counts.size()) {
            if (counts[i] == 0) {
                i++;
                continue;
            }
            counts[i]--;
            int j = i + 1;
            while(j < counts.size()) {
                if (counts[j] > counts[j - 1]) {
                    counts[j]--;
                    j++;
                } else {
                    break;
                }
            }
                        
            if (j - i <= 2) {
                return false;
            }
        }
        return true;
    }
};
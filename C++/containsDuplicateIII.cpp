class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (k < 1 || t < 0) return false;

        int64_t bucketWidth = (int64_t)t + 1; 

        #define BUCKET_ID(number) ((number/bucketWidth) - (number < 0 ? 1 : 0))
        unordered_map<int64_t,int64_t> buckets;
        
        for (int idx = 0; idx < nums.size(); ++idx) {
            int64_t bucketId = BUCKET_ID(nums[idx]);
            
            if (buckets.count(bucketId))
                return true;
            else if (buckets.count(bucketId-1) && nums[idx]-buckets[bucketId-1] <= t)
                return true;
            else if (buckets.count(bucketId+1) && buckets[bucketId+1]-nums[idx] <= t)                         return true;

            buckets[bucketId] = nums[idx];
            
            if (idx+1 > k)
                buckets.erase(BUCKET_ID(nums[idx-k]));
        }
        
        return false;
    }
};
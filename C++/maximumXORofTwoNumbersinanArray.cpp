class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        int mask = 0;
        unordered_set<int> s;
        for (int i = 31; i >= 0; i--) {
            s.clear();
            mask |= 1 << i;
            for (int num : nums) {
                s.insert(num & mask);
            }
            int tmp = res | (1 << i);
            for (int pre : s) {
                if (s.count(tmp ^ pre)) {
                    res = tmp;
                    break;
                }
            }
        }
        return res;
    }
};
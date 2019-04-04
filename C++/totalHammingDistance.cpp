class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int result = 0, current, l =nums.size();
        for (int i=0; i<30; i++){
            current = 0;
            for (int& n:nums){
                current += (n%2);
                n /= 2;
            }
            result += current*(l-current);
        }
        return result;
    }
};
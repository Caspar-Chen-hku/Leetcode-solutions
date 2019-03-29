class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int numzero = 0;
        for (int i=0; i<nums.size(); i++){
            if (nums[i]==0){
                nums.erase(nums.begin()+i);
                numzero++; i--;
            }
        }
        for (int i=0; i<numzero; i++){
            nums.push_back(0);
        }
    }
};
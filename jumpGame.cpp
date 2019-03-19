class Solution {
public:
    
    bool canJumpCheck(vector<int>& nums, int index, bool* indices){
        int step = nums[index];
        for (int i=index+1; i<=index+step; i++){
            if (indices[i]){
                return true;
            }
        }
        return false;
    }
    
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        bool* indices = new bool[n];
        indices[n-1]=true;
        for (int i=n-2; i>=0; i--){
            indices[i]=canJumpCheck(nums,i,indices);
        }
        bool result = indices[0];
        delete[] indices;
        return result;
    }
};
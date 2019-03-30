class NumArray {
public:
    
    int* sumUntil;
    
    NumArray(vector<int> nums) {
        sumUntil = new int[nums.size()];
        if (nums.empty()) return;
        sumUntil[0] = nums[0];
        for (int i=1; i<nums.size(); i++){
            sumUntil[i] = sumUntil[i-1] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        if (i==0){
            return sumUntil[j];
        }else{
            return sumUntil[j] - sumUntil[i-1];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
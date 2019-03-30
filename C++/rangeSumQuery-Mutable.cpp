class NumArray {
public:
    
    int* sumUntil;
    vector<int> original;
    
    NumArray(vector<int> nums) {
        sumUntil = new int[nums.size()];
        if (nums.empty()) return;
        sumUntil[0] = nums[0];
        for (int i=1; i<nums.size(); i++){
            sumUntil[i] = sumUntil[i-1] + nums[i];
        }
        original = nums;
    }
    
    int sumRange(int i, int j) {
        if (i==0){
            return sumUntil[j];
        }else{
            return sumUntil[j] - sumUntil[i-1];
        }
    }
    
    void update(int ind, int val) {
        int toup = val - original[ind];
        for (int i=ind; i<original.size(); i++){
            sumUntil[i] += toup;
        }
        original[ind] = val;
    }
    
};
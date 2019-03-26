class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index=0;
        int s = nums.size();
        if (s==1) return;
        for (int i=s-1; i>0; i--){
            if (nums[i]>nums[i-1]){
            index=i; break;}
        }
        if (index==0){
            reverse(nums.begin(),nums.end());
            return;
        }
        int j=s-1;
        for (int i=index; i<s; i++){
            if (i<s-1&&nums[i+1]<=nums[index-1]){
                j=i; break;
            }
        }
        swap(nums[index-1],nums[j]);
        reverse(nums.begin()+index,nums.end());
    }
    
    void swap(int& i, int& j){
        int temp = i;
        i = j;
        j = temp;
    }
};
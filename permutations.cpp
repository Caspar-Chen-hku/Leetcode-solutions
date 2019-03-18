class Solution {
public:
    
    void exchange(vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    vector<vector<int> > recursive_permute(vector<int>& nums, int index) {
        vector<int> part;
        vector<vector<int> > result;
        vector<vector<int> > prev;
        if (index==0){
            part.push_back(nums[0]);
            result.push_back(part);
            return result;
        }
        for (int i=0; i<=index; i++){
            exchange(nums,i,index);
            prev = recursive_permute(nums,index-1);
            for (int j=0; j<prev.size(); j++){
                prev[j].push_back(nums[index]);
            }
            result.insert(result.end(),prev.begin(),prev.end());
            exchange(nums,i,index);
        }
        return result;
    }
    
    vector<vector<int> > permute(vector<int>& nums) {
        return recursive_permute(nums,nums.size()-1);
    }
};
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = nums.size();
        int i=0, j=s-1, p=-1;
        while (i<=j){
            p = (i+j)/2;
            if (p==s-1||nums[p]>nums[p+1]) break;
            else if (i==j) {p=-1; break;}
            else if(nums[0]<=nums[p]) i=p+1;
            else j=p-1;
        }
        if (p==-1) return -1;
        cout << "P:" << p << endl;
        if (target<nums[0]){
            return binSearch(nums,target,p+1,s-1);
        }else{
            return binSearch(nums,target,0,p);
        }
        
    }
    
    int binSearch(vector<int>& nums, int target, int i, int j){
        int p=-1;
        while (i<=j){
            p = (i+j)/2;
            if (nums[p]==target) return p;
            else if (i==j) return -1;
            else if(nums[p]>target) j=p-1;
            else i=p+1;
        }
        return -1;
    }
};
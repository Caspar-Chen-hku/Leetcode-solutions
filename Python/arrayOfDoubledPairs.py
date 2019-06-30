class Solution {
public:
    
    static bool compare(int& a, int& b){
        return abs(a) < abs(b); 
    }
    
    bool canReorderDoubled(vector<int>& A) {
        sort(A.begin(), A.end(), compare);
        map<int,int> nums;
        for (int i:A){
            nums[i]++;
        }
        for (int i:A){
            if (nums[i]<=0) continue;
            else if (nums[2*i]<=0) return false;
            nums[i]--;
            nums[2*i]--;
        }
        return true;
    }
};
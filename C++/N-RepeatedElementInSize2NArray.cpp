class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        set<int> nums;
        for (int a:A){
            if (nums.find(a)==nums.end()){
                nums.insert(a);
            }else{
                return a;
            }
        }
        return -1;
    }
};
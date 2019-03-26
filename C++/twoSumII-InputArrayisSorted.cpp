class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        if (numbers.size()<2) return result;
        int i=0, j=numbers.size()-1;
        while (i<=j){
            if (numbers[i]+numbers[j]<target){
                i++;
            }else if (numbers[i]+numbers[j]>target){
                j--;
            }else{
                result.push_back(i+1);
                result.push_back(j+1);
                return result;
            }
        }
        return result;
    }
};
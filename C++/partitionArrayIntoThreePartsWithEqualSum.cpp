class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        long long sum = 0, cur = 0;
        for (int i:A){
            sum += i;
        }
        if (sum%3!=0) return false;
        int count = 0;
        for (int i:A){
            cur += i;
            if (cur==sum/3){
                cur = 0; count++;
            }
        }
        return (count==3);
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=prices.size();
        if (l<2) return 0;
        int result = 0, curmin = prices[0], temp, total = 0;
        for (int i=1; i<l; i++){
            if (prices[i]<prices[i-1]){
                curmin=prices[i];
                total += result;
                result = 0;
            }else{
                temp = prices[i]-curmin;
                if (temp>result){
                    result = temp;
                }
            }
        }
        total += result;
        return total;
    }
};
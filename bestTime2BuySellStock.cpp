class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=prices.size();
        if (l<2) return 0;
        int result = 0, curmin = prices[0], temp;
        for (int i=1; i<l; i++){
            if (prices[i]<curmin){
                curmin=prices[i];
            }else{
                temp = prices[i]-curmin;
                if (temp>result){
                    result = temp;
                }
            }
        }
        return result;
    }
};
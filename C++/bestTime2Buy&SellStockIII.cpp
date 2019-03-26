class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0, temp, l=prices.size();
        for (int i=0; i<l; i++){
            temp = max(prices,0,i) + max(prices,i+1,l-1);
            if (temp>result) result=temp;
        }
        return result;
    }
    
    int max(vector<int>& prices, int start, int end){
        if (end<=start){
            return 0;
        }
        int l=prices.size();
        int result = 0, curmin = prices[start], temp;
        for (int i=start+1; i<=end; i++){
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
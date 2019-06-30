class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int additional, cur = 0, sum = 0;
        for (int i=0; i<X; i++){
            if (grumpy[i]){
                cur += customers[i];
            }else{
                sum += customers[i];   
            }
        }
        additional = cur;
        for (int i=X; i<grumpy.size(); i++){
            if (grumpy[i]){
                cur += customers[i];
            }else{
                sum += customers[i];
            }
            if (grumpy[i-X]){
                cur -= customers[i-X];
            }
            additional = max(cur, additional);
        }
        return sum + additional;
    }
};
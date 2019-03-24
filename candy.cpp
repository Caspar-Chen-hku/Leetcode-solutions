class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.empty()) return 0;
        int l = ratings.size();
        int* left = new int[l];
        int* right = new int[l];
        left[0]=1; right[l-1]=1;
        for (int i=1; i<l; i++){
            if (ratings[i]>ratings[i-1]){
                left[i]=left[i-1]+1;
            }else{
                left[i]=1;
            }
        }
        for (int i=l-2; i>=0; i--){
            if (ratings[i]>ratings[i+1]){
                right[i]=right[i+1]+1;
            }else{
                right[i]=1;
            }
        }
        int sum = 0;
        for (int i=0; i<l; i++){
            sum += (left[i]>right[i]?left[i]:right[i]);
        }
        return sum;
    }
};
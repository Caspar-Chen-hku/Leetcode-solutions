class Solution {
public:
    int maximumSum(vector<int>& arr) {
        vector<int> maxleft(arr.size(), 0);
        vector<int> maxright(arr.size(), 0);
        maxleft[0] = arr[0];
        maxright[arr.size()-1] = arr.back();
        int res = max(maxleft[0], maxright.back());
        for (int i=1; i<arr.size(); i++){
            maxleft[i] = max(maxleft[i-1]+arr[i], arr[i]);
            res = max(res, maxleft[i]);
        }
        for (int i=arr.size()-2; i>=0; i--){
            maxright[i] = max(maxright[i+1] + arr[i], arr[i]);
            res = max(res, maxright[i]);
        }
        for (int i=1; i<arr.size()-1; i++){
            res = max(res, maxleft[i-1]+maxright[i+1]);
        }
        return res;
    }
};
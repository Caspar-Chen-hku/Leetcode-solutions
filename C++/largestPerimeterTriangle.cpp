class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        int l = A.size(), temp;
        for (int i=l-3; i>=0; i--){
            temp = A[i]+A[i+1];
            if (temp>A[i+2]){
                return temp+A[i+2];
            }
        }
        return 0;
    }
};
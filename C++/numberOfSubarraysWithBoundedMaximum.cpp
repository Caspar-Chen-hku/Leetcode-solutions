class Solution {
public:
    Solution() {
      cin.tie(0);
      ios::sync_with_stdio(false);
    }
    
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int min = -1;
        int max = -1;
        int s = 0;
        for (int i = 0; i < A.size(); i++)
        {
            if (L <= A[i] && A[i] <= R)
                max = i;
            else if (A[i] > R)
                max = min = i;
            s += max - min;
        }
        return s;
    }
};

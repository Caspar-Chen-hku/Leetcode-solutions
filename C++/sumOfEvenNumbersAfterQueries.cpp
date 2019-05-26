class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int sum = 0;
        for (int a:A){
            if (a%2==0){
                sum += a;
            }
        }
        int ind, val;
        vector<int> res;
        for (vector<int> q:queries){
            ind = q[1]; val = q[0];
            if (A[ind]%2==0){
                if (val%2==0){
                    sum += val;
                }else{
                    sum -= A[ind];
                }
                A[ind] += val;
            }else{
                A[ind] += val;
                if (val%2!=0){
                    sum += A[ind];
                }
            }
            res.push_back(sum);
        }
        return res;
    }
};
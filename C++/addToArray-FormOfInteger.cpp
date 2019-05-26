class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> ans;
        int co = 0, temp = 0, i = A.size()-1;
        while (i>=0 || K>0 || co>0){
            temp = co + K%10;
            if (i>=0){
                temp += A[i];
                A[i] = temp%10;
            }else{
                A.insert(A.begin(), temp%10);
            }
            co = temp/10;
            K /= 10; i--;
        }
        return A;
    }
};
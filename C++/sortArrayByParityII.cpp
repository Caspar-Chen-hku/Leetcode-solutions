class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i=0, j=1, l=A.size(), temp;
        while (i<l && j<l){
            while (i<l && A[i]%2==0) i+=2;
            while (j<l && A[j]%2==1) j+=2;
            if (i<l && j<l){
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                i+=2; j+=2;
            }
        }
        return A;
    }
};
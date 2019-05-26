class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0, j = A.size()-1, temp;
        while (i<j){
            if (A[i]%2==0 && A[j]%2==0){
                i++;
            }else if (A[i]%2==1 && A[j]%2==1){
                j--;
            }else{
                if (A[i]%2==1 && A[j]%2==0){
                    temp = A[i];
                    A[i] = A[j];
                    A[j] = temp;
                }
                i++; j--;
            }
        }
        return A;
    }
};
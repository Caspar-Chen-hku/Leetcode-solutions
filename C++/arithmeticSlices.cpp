class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int num = 0, l = A.size(), temp;
        if (l<3) return 0;
        int** sol = new int*[l-2];
        for (int i=0; i<l-2; i++){
            sol[i] = new int[l];
        }
        for (int i=0; i<l-2; i++){
            temp = A[i+1]-A[i];
            if (temp==A[i+2]-A[i+1]){
                sol[i][i+2] = temp; num++;
            }else{
                sol[i][i+2] = INT_MAX;
            }
        }
        for (int len=4; len<=l; len++){
            for (int i=0; i<=l-len; i++){
                if (A[i+len-1]-A[i+len-2]==sol[i][i+len-2]){
                    sol[i][i+len-1] = sol[i][i+len-2]; num++;
                }else{
                    sol[i][i+len-1] = INT_MAX;
                }
            }
        }
        return num;
    }
};
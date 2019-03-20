class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        if (m==0) return false;
        int n=matrix[0].size();
        if (n==0) return false;
        int i=0, j=m-1, row, col;
        while (i<=j){
            row=(i+j)/2;
            if (matrix[row][0]<=target && (row==m-1 || matrix[row+1][0]>target)){
                break;
            }else if (matrix[row][0]<target){
                i = row+1;
            }else{
                j = row-1;
            }
        }
        i=0; j=n-1;
        while (i<=j){
            col = (i+j)/2;
            if (matrix[row][col]==target) return true;
            else if (matrix[row][col]<target) i=col+1;
            else j=col-1;
        }
        return false;
    }
};
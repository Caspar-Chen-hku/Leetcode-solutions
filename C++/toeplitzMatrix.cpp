class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int i = m-1, j = 0, target;
        while (j<n){
            target = matrix[i][j];
            for (int x=i+1, y=j+1; x<m&&y<n; x++, y++){
                if (matrix[x][y]!=target) return false;
            }
            if (i>0) i--;
            else j++;
        }
        return true;
    }
};
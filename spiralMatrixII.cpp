class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        fillMatrix(matrix,0,0,n-1,n-1,1);
        return matrix;
    }
    
    int fillMatrix(vector<vector<int>>& matrix, int x1, int y1, int x2, int y2, int start){
        if (x1>x2) return start;
        else if (x1==x2) {
            matrix[x1][y1] = start;
            return start+1;
        }
        for (int i=0; i<y2-y1; i++){
            matrix[x1][y1+i] = start+i;
        }
        start+=y2-y1;
        for (int i=0; i<y2-y1; i++){
            matrix[x1+i][y2] = start+i;
        }
        start+=y2-y1;
        for (int i=0; i<y2-y1; i++){
            matrix[x2][y2-i] = start+i;
        }
        start+=y2-y1;
        for (int i=0; i<y2-y1; i++){
            matrix[x2-i][y1] = start+i;
        }
        start+=y2-y1;
        start = fillMatrix(matrix,x1+1,y1+1,x2-1,y2-1,start);
        return start;
    }
};
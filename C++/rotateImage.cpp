class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int x=matrix.size();
        int y=matrix[0].size();
        rotateRec(matrix,0,0,x-1,y-1);
    }
    
    void rotateRec(vector<vector<int>>& matrix, int x1, int y1, int x2, int y2){
        if (x1>=x2||y1>=y2) return;
        vector<int> temp;
        temp.insert(temp.begin(),matrix[x1].begin()+y1,matrix[x1].begin()+y2+1);
        for (int i=0; i<=x2-x1; i++){
            matrix[x1][y1+i]=matrix[x2-i][y1];
        }
        for (int i=0; i<=x2-x1; i++){
            matrix[x1+i][y1]=matrix[x2][y1+i];
        }
        for (int i=0; i<=x2-x1; i++){
            matrix[x2][y1+i]=matrix[x2-i][y2];
        }
        for (int i=0; i<=x2-x1; i++){
            matrix[x1+i][y2]=temp[i];
        }
        rotateRec(matrix,x1+1,y1+1,x2-1,y2-1);
    }
};
class Solution {
public:
    
    vector<int> spiralOrderRecursive(vector<vector<int> >& matrix, int x1, int y1, int x2, int y2){
        vector<int> result;
        if (x1>x2||y1>y2){
            return result;
        } 
        for (int i=y1; i<=y2; i++){
            result.push_back(matrix[x1][i]);
        }
        for (int i=x1+1; i<=x2; i++){
            result.push_back(matrix[i][y2]);
        }
        for (int i=y2-1; i>=y1&&x1!=x2; i--){
            result.push_back(matrix[x2][i]);
        }
        for (int i=x2-1; i>x1&&y1!=y2; i--){
            result.push_back(matrix[i][y1]);
        }
        vector<int> temp = spiralOrderRecursive(matrix, x1+1, y1+1, x2-1, y2-1);
        result.insert(result.end(), temp.begin(), temp.end());
        return result;
    }
    
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> result;
        int x2=matrix.size()-1;
        if (x2==-1){
            return result;
        }
        int y2 = matrix[0].size()-1;
        return spiralOrderRecursive(matrix, 0, 0, x2, y2);
    }
};
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) return 0;
        int l =triangle.size();
        int* result = new int[l];
        for (int i=0; i<l; i++){
            result[i] = triangle[l-1][i];
        }
        for (int i=l-2; i>=0; i--){
            for (int j=0; j<=i; j++){
                result[j] = triangle[i][j] + min(result[j],result[j+1]);
            }
        }
        return result[0];
    }
    
    int min(int i, int j){
        return (i>j?j:i);
    }
};
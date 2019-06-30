class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int down = 0, right = 1, step = 1, r = r0, c = c0;
        vector<vector<int>> res;
        while (step <= 2*max(R, C)){
            for (int i=0; i<step; i++){
                if (r>=0 && r<R && c>=0 && c<C)
                    res.push_back({r, c});
                r += down; c += right;
            }
            if (down == 0){
                down = (right == 1 ? 1 : -1);
                right = 0;
            }else{
                right = (down == 1 ? -1 : 1);
                down = 0; step++;
            }
        }
        return res;
    }
};
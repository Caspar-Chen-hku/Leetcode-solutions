class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m = nums.size(), n = nums[0].size();
        if (m*n!=r*c){
            return nums;
        }else{
            vector<vector<int>> res(r, vector<int>(c, 0));
            int indr = 0, indc = 0;
            for (int i=0; i<r; i++){
                for (int j=0; j<c; j++){
                    res[i][j] = nums[indr][indc];
                    indc++;
                    if (indc==n){
                        indr++;
                        indc=0;
                    }
                }
            }
            return res;
        }
    }
};
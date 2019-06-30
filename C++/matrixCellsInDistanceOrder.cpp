class Solution {
public:
    
    vector<vector<int>> res;
    
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        res.push_back({r0, c0});
        for (int i=1; ; i++){
            if (!add(R, C, r0, c0, i)){
                break;
            }
        }
        return res;
    }
    
    bool add(int R, int C, int r0, int c0, int dis){
        int c;
        bool exist = false;
        for (int r=0; r<=dis; r++){
            c = dis-r;
            if (r0-r>=0){
                if (c0-c>=0){
                    exist = true;
                    res.push_back({r0-r, c0-c});
                }
                if (c0+c<C && c>0){
                    exist = true;
                    res.push_back({r0-r, c0+c});
                }
            }
            if (r0+r<R && r>0){
                if (c0-c>=0){
                    exist = true;
                    res.push_back({r0+r, c0-c});
                }
                if (c0+c<C && c>0){
                    exist = true;
                    res.push_back({r0+r, c0+c});
                }
            }
        }
        return exist;
    }
    
};
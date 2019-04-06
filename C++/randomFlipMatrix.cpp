class Solution {
public:
    
    int row;
    int col;
    set<vector<int>> used;
    
    Solution(int n_rows, int n_cols) {
        row = n_rows;
        col = n_cols;
    }
    
    vector<int> flip() {
        int x = rand()%row;
        int y = rand()%col;
        if (used.find({x,y})!=used.end()){
            return flip();
        }else{
            used.insert({x,y});
            return {x,y};
        }
    }
    
    void reset() {
        used.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
class Solution {
public:
    
    vector<vector<int>> points;
    
    Solution(vector<vector<int>>& rects) {
        points = rects;   
    }
    
    vector<int> pick() {
        int sum = 0, area;
        vector<int> selected;
        for (auto v:points){
            area = (v[2]-v[0]+1)*(v[3]-v[1]+1);
            sum += area;
            if (rand()%sum<area) selected=v;
        }
        return vector<int>{selected[0] + rand()%(selected[2]-selected[0]+1),
                           selected[1] + rand()%(selected[3]-selected[1]+1)};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
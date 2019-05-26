class Solution {
public:
    
    vector<int> sums;
    
    Solution(vector<int>& w) {
        if (w.empty()) return;
        sums = vector<int>(w.size(), 0);
        sums[0] = w[0];
        for (int i=1; i<w.size(); i++){
            sums[i] = sums[i-1] + w[i];
        }
    }
    
    int pickIndex() {
        int x = rand()%(sums.back());
        for (int i=0; i<sums.size(); i++){
            if (x<sums[i]) return i;
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
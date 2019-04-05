class Solution {
public:
    vector<int> constructRectangle(int area) {
        bool bigger = false;
        for (int i=(int) sqrt(area); i<=area; i++){
            bigger = bigger || i*i>=area;
            if (bigger && area%i==0){
                vector<int> res{i,area/i};
                return res;
            }
        }
        vector<int> res{area,1};
        return res;
    }
};
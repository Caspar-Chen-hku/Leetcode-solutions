class Solution {
public:
    
    double r;
    double x;
    double y;
    
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
    }
    
    vector<double> randPoint() {
        double fx = (double) rand() / RAND_MAX;
        double fy = (double) rand() / RAND_MAX;
        fx = (x-r) + fx*2*r;
        fy = (y-r) + fy*2*r;
        if ((fx-x)*(fx-x)+(fy-y)*(fy-y)<=r*r){
            vector<double> res{fx,fy};
            return res;
        }else{
            return randPoint();
        }
    }
};

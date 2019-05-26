class Solution {
public:
    
    static bool compare(vector<int> p1, vector<int> p2){
        if (p1[0]==p2[0]) return (p1[1]>p2[1]);
        else return (p1[0]<p2[0]);
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points{p1,p2,p3,p4};
        sort(points.begin(), points.end(), compare);
        return points[0]!=points[1]  
            && (abs(points[3][0]-points[2][0]) == abs(points[1][0]-points[0][0]))
            && (abs(points[3][1]-points[2][1]) == abs(points[1][1]-points[0][1]))
            && ((points[1][0]-points[0][0])*(points[2][0]-points[0][0])
            +  (points[1][1]-points[0][1])*(points[2][1]-points[0][1]) == 0)
            && (abs(points[1][0]-points[0][0])==abs(points[2][1]-points[0][1]))
            && (abs(points[0][1]-points[1][1])==abs(points[2][0]-points[0][0]));
    }
};
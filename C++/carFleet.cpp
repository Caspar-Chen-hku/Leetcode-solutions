class Solution {
public:
    
    static bool compare(pair<int,double> i, pair<int,double> j){
        return (i.first > j.first);    
    }
    
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int l = position.size();
        if (l==0) return 0;
        vector<pair<int,double>> cars;
        for (int i=0; i<l; i++){
            cars.push_back(make_pair(position[i], (target-position[i])*1.0/speed[i]));
        }
        sort(cars.begin(), cars.end(), compare);
        int i = 0, j = 1, numFleet = 1;
        while (j<l){
            if (cars[j].second <= cars[i].second){
                j++;
            }else{
                numFleet++; i=j; j++;
            }
        }
        return numFleet;
    }
};
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int current = 0, temp = 0, lastind = 0, j;
        
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        
        current = max(current, heaters[0]-houses[0]);
        current = max(current, houses.back()-heaters.back());
        
        for (int i=0; i<heaters.size()-1; i++){
            temp = 0;
            for (j=lastind; j<houses.size(); j++){
                if (houses[j]<=heaters[i]) continue;
                else if (houses[j]>=heaters[i+1]) break;
                temp = max(temp, min(houses[j]-heaters[i],heaters[i+1]-houses[j]));
            }
            current = max(temp, current);
            lastind = j;
            if (lastind>=houses.size()) break;
        }
        return current;
    }
};
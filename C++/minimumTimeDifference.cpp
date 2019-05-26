class Solution {
public:
    int convertTime(string num, int beg){
        return stoi(num.substr(beg,2));
    }

    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        
        for(int i = 0; i < timePoints.size(); i++){
            int hours = convertTime(timePoints[i],0);
            int min = convertTime(timePoints[i],3);
            minutes.push_back(hours*60+min);
        }
        sort(minutes.begin(), minutes.end());
        
        int minimum = minutes[0]+1440 - minutes.back();
        
        for(int i = 0; i <timePoints.size()-1; i++){
            int temp = minutes[i+1]-minutes[i];
            minimum = min(minimum, temp);
        }
        return minimum;
    }
};
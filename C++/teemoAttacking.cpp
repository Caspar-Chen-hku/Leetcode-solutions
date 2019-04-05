class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;
        int time = duration;
        for (int i=1; i<timeSeries.size(); i++){
            time += min(timeSeries[i]-timeSeries[i-1], duration);
        }
        return time;
    }
};
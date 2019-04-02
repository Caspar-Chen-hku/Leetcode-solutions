/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool compare(Interval a, Interval b){
    return (a.end < b.end);
}

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end(), compare);
        int count = 1, last = 0, temp, l=intervals.size();
        while (last<l){
            temp = -1;
            for (int i=last+1; i<l; i++){
                if (intervals[i].start>=intervals[last].end){
                    temp = i; break;
                }
            }
            if (temp==-1) break;
            else{
                count++; last=temp;
            }
        }
        return (l-count);
    }
};
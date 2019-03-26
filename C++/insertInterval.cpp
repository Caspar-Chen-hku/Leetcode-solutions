/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int s=newInterval.start, e=newInterval.end, len=intervals.size();
        int* result1 = findIndex(intervals,s,0,len-1);
        int* result2 = findIndex(intervals,e,result1[0],len-1);
        vector<Interval> result;
        result.insert(result.end(),intervals.begin(),intervals.begin()+result1[0]);
        if (result2[1]==-1){
            if (result1[1]==1){
                newInterval.start=intervals[result1[0]].start;
            }
            result.push_back(newInterval);
            result.insert(result.end(),intervals.begin()+result2[0],intervals.end());
        }else{
            newInterval.end = intervals[result2[0]].end;
            if (result1[1]==1){
                newInterval.start=intervals[result1[0]].start;
            }
            result.push_back(newInterval);
            result.insert(result.end(),intervals.begin()+result2[0]+1,intervals.end());
        }
        return result;
    }
    
    //return [i,b]; b: -1: before i, 1: in i
    int* findIndex(vector<Interval>& intervals, int target, int i, int j){
        int temp;
        int* result = new int[2];
        while (i<=j){
            temp = (i+j)/2;
            if ((temp==0 || intervals[temp-1].end<target ) &&intervals[temp].start>target){
                result[0] = temp; result[1] = -1; return result;
            }else if (intervals[temp].start<=target&&intervals[temp].end>=target){
                result[0] = temp; result[1] = 1; return result;
            }else if(intervals[temp].end<target){
                i=temp+1;
            }else{
                j=temp-1;
            }
        }
        result[0] = j+1, result[1] = -1; return result;
    }
};
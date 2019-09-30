class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if (start > destination){
            return distanceBetweenBusStops(distance, destination, start);
        }
        int dis1 = 0, dis2 = 0;
        for (int i=start; i<destination; i++){
            dis1 += distance[i];
        }
        for (int i=0; i<start; i++){
            dis2 += distance[i];
        }
        for (int i=destination; i<distance.size(); i++){
            dis2 += distance[i];
        }
        return min(dis1, dis2);
    }
};
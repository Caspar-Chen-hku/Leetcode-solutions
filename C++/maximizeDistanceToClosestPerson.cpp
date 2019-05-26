class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> ones;
        for (int i=0; i<seats.size(); i++){
            if (seats[i]==1){
                ones.push_back(i);
            }
        }
        int maxDis = max(ones[0], (int) seats.size()-1-ones.back());
        for (int i=0; i<ones.size()-1; i++){
            maxDis = max(maxDis, (ones[i+1]-ones[i])/2);
        }
        return maxDis;
    }
};
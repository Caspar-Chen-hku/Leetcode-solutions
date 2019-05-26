class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int boat = 0, i = 0, j = people.size()-1;
        while (i<j){
            if (people[i]+people[j]<=limit){
                i++; j--;
            }else{
                j--;
            }
            boat++;
        }
        return (i==j?boat+1:boat);
    }
};
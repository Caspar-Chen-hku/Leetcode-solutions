class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        return min(set<int>(candies.begin(), candies.end()).size(), candies.size()/2);
    }
};
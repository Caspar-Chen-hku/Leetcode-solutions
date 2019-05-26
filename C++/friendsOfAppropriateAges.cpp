class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        map<int,int> ageCount;
        for (int a:ages){
            ageCount[a]++;
        }
        int res = 0;
        for (auto e1:ageCount){
            for (auto e2:ageCount){
                if (e2.first <= 0.5*e1.first + 7) continue;
                else if (e2.first > e1.first) continue;
                else if (e2.first > 100 && e1.first < 100) continue;
                res += e1.second*e2.second;
                if (e1==e2) res -= e1.second;
            }
        }
        return res;
    }
};
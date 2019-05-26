class Solution {
public:
    int findLHS(vector<int>& nums) {
        if (nums.empty()) return 0;
        map<int,int> m;
        for (int n:nums){
            m[n]++;
        }
        int cur = 0;
        pair<int,int> lastone;
        bool start = true;
        for (auto it=m.begin(); it!=m.end(); it++){
            if (start){
                start=false; lastone = *it;
            }else{
                if (it->first == lastone.first+1){
                    cur = max(cur, lastone.second + it->second);
                }
                lastone = *it;
            }
        }
        return cur;
    }
};
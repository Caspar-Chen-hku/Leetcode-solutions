class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> result;
        map<int,vector<pair<int,int>>> sum;
        
        for (auto e1:nums1){
            for (auto e2:nums2){
                sum[e1+e2].push_back(make_pair(e1,e2));
            }
        }
        
        for (auto e1:sum){
            for (auto e2:e1.second){
                if (k<=0) break;
                result.push_back(e2);
                k--;
            }
            if (k<=0) break;
        }
        return result;
    }
};
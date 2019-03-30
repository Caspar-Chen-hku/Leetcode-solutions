class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> n1;
        for (auto e:nums1){
            if (n1.count(e)==0){
                n1[e]=1;
            }
        }
        for (auto e:nums2){
            if (n1.count(e)==1){
                n1[e]=2;
            }
        }
        vector<int> res;
        for (auto it=n1.begin(); it!=n1.end(); it++){
            if (it->second==2) res.push_back(it->first);
        }
        return res;
    }
};
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> n1;
        unordered_map<int,int> n2;
        for (auto e:nums1) n1[e]++;
        for (auto e:nums2) n2[e]++;
        vector<int> res;
        int temp;
        for (auto it=n1.begin(); it!=n1.end(); it++){
            temp = 0;
            if (n2.count(it->first)>0){
                temp = min(it->second,n2[it->first]);
            }
            while (temp>0){
                res.push_back(it->first); temp--;
            }
        }
        return res;
    }
};
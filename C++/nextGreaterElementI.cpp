class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>::iterator it;
        vector<int> res;
        int temp;
        for (int n:nums1){
            it = find(nums2.begin(),nums2.end(),n);
            temp = -1;
            for (auto i=it+1; i!=nums2.end(); i++){
                if ((*i)>n){
                    temp = *i; break;
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};
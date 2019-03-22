class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j=0;
        while (j<n){
            if (i<m&&nums1[i]<nums2[j]){
                i++;
            }else{
                nums1.insert(nums1.begin()+i,nums2[j]);
                i++; j++; m++;
                nums1.pop_back();
            }
        }
    }
};
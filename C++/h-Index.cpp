class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int l = citations.size();
        int i=0, j=l-1, mid;
        while (i<=j){
            mid = (i+j)/2;
            if (citations[mid]>=l-mid && (mid==0 || citations[mid-1]<=l-mid)){
                return l-mid;
            }else if (citations[mid]<l-mid){
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
        return 0;
    }
};
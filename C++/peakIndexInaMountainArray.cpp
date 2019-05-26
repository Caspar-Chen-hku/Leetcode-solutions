class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int i=0, j=A.size()-1, mid;
        while (i<=j){
            mid = (i+j)/2;
            if (mid>0 && mid<A.size()-1 && A[mid]>A[mid-1] && A[mid]>A[mid+1]){
                return mid;
            }else if (mid<A.size()-1 && A[mid]<A[mid+1]){
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
        return -1;
    }
};
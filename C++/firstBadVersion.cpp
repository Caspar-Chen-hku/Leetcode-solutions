// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long i=1, j=n, mid;
        bool temp;
        while (i<=j){
            mid = (i+j)/2;
            temp = isBadVersion(mid);
            if (temp && (mid==0 || !isBadVersion(mid-1))){
                return mid;
            }else if (!temp){
                i=mid+1;
            }else{
                j=mid-1;
            }
        }
        return -1;
    }
};
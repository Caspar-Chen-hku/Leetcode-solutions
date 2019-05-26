class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int i = 0, l = A.size();
        bool upped = false, downed = false;
        while (i+1<l && A[i+1]>A[i]){
            i++;
            upped = true;
        }
        while (upped && i+1<l && A[i+1]<A[i]){
            i++;
            downed = true;
        }
        return (downed && i==l-1);
    }
};
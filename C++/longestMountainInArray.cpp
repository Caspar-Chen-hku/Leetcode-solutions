class Solution {
public:
    int longestMountain(vector<int>& A) {
        bool up = false, down = false;
        int maxLen = 0, i = 0, j = 0;
        bool upped = false, downed = false;
        while (i<A.size()){
            j = i; upped = false; downed = false;
            while (j+1<A.size()&&A[j+1]>A[j]){
                j++; upped = true;
            }
            while (j+1<A.size()&&A[j+1]<A[j]){
                j++; downed = true;
            }
            if (upped && downed){
                maxLen = max(maxLen, j-i+1);  
            }
            i = max(j, i+1);
        }
        return maxLen;
    }
};
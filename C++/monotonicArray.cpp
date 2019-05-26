class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool mono = true;
        for (int i=0; i<A.size()-1; i++){
            if (A[i]>A[i+1]){
                mono = false; break;
            }
        }
        if (mono) return true;
        mono = true;
        for (int i=0; i<A.size()-1; i++){
            if (A[i]<A[i+1]){
                mono = false; break;
            }
        }
        return mono;
    }
};
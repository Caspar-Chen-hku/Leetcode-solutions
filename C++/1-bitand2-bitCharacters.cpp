class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int l = bits.size();
        if (l<=1) return true;
        bool* valid = new bool[l+1];
        valid[0] = true;
        valid[1] = bits[0]==0;
        for (int i=2; i<=l; i++){
            if (bits[i-1]==0){
                valid[i] = valid[i-1] || (bits[i-2]==1 && valid[i-2]);
            }else{
                valid[i] = bits[i-2]==1 && valid[i-2];
            }
        }
        return valid[l-1] && (bits[l-2]==0 || !valid[l-2]);
    }
};
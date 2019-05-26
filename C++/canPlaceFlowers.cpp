class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int l = flowerbed.size();
        if (n==0) return true;
        else if (l==0) return false;
        else if (l==1) return (flowerbed[0]==0 && n==1);
        for (int i=0; i<l; i++){
            if (i==0){
                if (flowerbed[0]==0 && flowerbed[1]==0){
                    n--; i++;
                }
            }else if (i==l-1){
                if (flowerbed[l-2]==0 && flowerbed[l-1]==0){
                    n--; i++;
                }
            }else if (flowerbed[i-1]==0 && flowerbed[i]==0 && flowerbed[i+1]==0){
                n--; i++;
            }
            if (n<=0) return true;
        }
        return false;
    }
};
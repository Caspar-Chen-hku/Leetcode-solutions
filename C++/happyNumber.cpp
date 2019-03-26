class Solution {
public:
    
    map<int,int> hmap;
    
    bool isHappy(int n) {
        if (n==1){
            return true;
        }else if (hmap.count(n)>0){
            return false;
        }else{
            hmap[n] = 1;
            return isHappy(digitSum(n));
        }
    }
    
    int digitSum(int n){
        int sol = 0, temp;
        while (n>0){
            temp = n%10;
            sol += temp*temp;
            n /= 10;
        }
        return sol;
    }
};
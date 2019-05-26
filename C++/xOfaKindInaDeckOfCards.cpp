class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        int curCount = 1;
        int prevNum = 0;
        sort(deck.begin(), deck.end());
        for (int i=1; i<deck.size(); i++){
            if (deck[i]==deck[i-1]){
                curCount++;
            }else{
                if (prevNum==0){
                    prevNum = curCount;
                }else{
                    prevNum = gcd(prevNum, curCount);   
                }
                if (prevNum<2) return false;
                curCount = 1;
            }
        }
        if (prevNum==0){
            prevNum = curCount;
        }else{
            prevNum = gcd(prevNum, curCount);   
        }
        return (prevNum>=2);
    }
    
    int gcd(int a, int b) { 
        if (b == 0) 
            return a; 
        return gcd(b, a % b);  
    }
};
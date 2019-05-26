class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int num = 0;
        vector<int> appear(501, 0);
        for (int i:time){
            appear[i]++;
        }
        for (int i=1; i<500; i++){
            if (appear[i]==0) continue;
            else if ((2*i)%60==0) num += appear[i]*(appear[i]-1)/2;
            for (int j=i+1; j<=500; j++){
                if (appear[j]==0) continue;
                else if ((i+j)%60==0) num += appear[i]*appear[j];
            }
        }
        return num;
    }
};
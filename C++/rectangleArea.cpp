class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int result = (C-A)*(D-B);
        if (C>E && G>A && D>F && H>B){
            int temp1, temp2;
            if (C<=G){
                temp1 = min(C-E,C-A);
            }else{
                temp1 = min(min(G-A,C-A),G-E);
            }
            if (F<=B){
                temp2 = min(H-B,D-B);
            }else{
                temp2 = min(min(D-F,D-B),H-F);
            }
            return result-temp1*temp2+(G-E)*(H-F);
        }
        return result+(G-E)*(H-F);
    }
};
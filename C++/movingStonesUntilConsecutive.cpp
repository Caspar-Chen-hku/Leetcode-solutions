class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int pos[3] = {a,b,c};
        sort(pos, pos+3);
        int minMove;
        if (pos[0]+1==pos[1] && pos[1]+1==pos[2]){
            minMove = 0;
        }else if (pos[1]<=pos[0]+2 || pos[2]<=pos[1]+2){
            minMove = 1;
        }else{
            minMove = 2;
        }
        return {minMove, (pos[2]-pos[1]-1) + (pos[1]-pos[0]-1)};
    }
};
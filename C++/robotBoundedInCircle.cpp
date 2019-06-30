class Solution {
public:
    vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
    
    bool isRobotBounded(string instructions) {
        
        vector<int> curPos = {0,0};
        int dir = 0;
        int t = 4;
        while(t-->0){
            for(char c:instructions){
                if(c == 'G'){
                    curPos[0] += dirs[dir][0];
                    curPos[1] += dirs[dir][1];
                }else if(c == 'R'){
                    dir = (dir+1)%4;
                }else{
                    dir = (dir-1 + 4)%4;
                }
            }
            if(curPos[0] == 0 && curPos[1] == 0 && dir == 0)
                return true;
        }
        return false;
    }
};
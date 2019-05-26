class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<vector<int>> obs(obstacles.begin(), obstacles.end());
        int up = 0, right = 0, dir = 0, ans = 0;
        for (int c:commands){
            if (c==-2){
                dir = (dir+3)%4;
            }else if (c==-1){
                dir = (dir+1)%4;
            }else{
                if (dir==0){
                    while (c>0 && obs.find({right, up+1})==obs.end()){
                        up++; c--;
                    }
                }else if (dir==1){
                    while (c>0 && obs.find({right+1, up})==obs.end()){
                        right++; c--;
                    }
                }else if (dir==2){
                    while (c>0 && obs.find({right, up-1})==obs.end()){
                        up--; c--;
                    }
                }else{
                    while (c>0 && obs.find({right-1, up})==obs.end()){
                        right--; c--;
                    }
                }
                ans = max(ans, up*up+right*right);
            }
        }
        return ans;
    }
};
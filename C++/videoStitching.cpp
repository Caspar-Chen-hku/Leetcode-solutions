class Solution {
public:
    
    static bool compare(vector<int>& c1, vector<int>& c2){
        if (c1[0] == c2[0]) return c1[1] > c2[1];
        else return c1[0] < c2[0];
    }
    
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end(), compare);
        if (clips[0][0]!=0) return -1;
        else if (clips[0][1]>=T) return 1;
        int count = 1, curend = clips[0][1], cur = 0;
        for (int i=1; i<clips.size(); i++){
            if (clips[i][0] > curend){
                if (cur > curend){
                    count++; curend = cur; cur = 0;
                }else{
                    return -1;
                }
                if (curend >= T) return count;
            }else if (clips[i][1] > curend){
                cur = max(cur, clips[i][1]);
            }
        }
        if (cur >= T){
            return count+1;
        }else{
            return -1;
        }
    }
};
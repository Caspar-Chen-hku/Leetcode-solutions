class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        int curMax = -1, l, h, m;
        for (int i=0; i<4; i++){
            for (int j=0; j<4; j++){
                if (j==i) continue;
                for (int k=0; k<4; k++){
                    if (k==i || k==j) continue;
                    l = 6-i-j-k;
                    h = 10*A[i]+A[j];
                    m = 10*A[k]+A[l];
                    if (h<24 && m<60){
                        curMax = max(curMax, h*60+m);
                    }
                }
            }
        }
        if (curMax<0){
            return "";
        }else{
            h = curMax/60; m = curMax%60;
            return ((h<10 ? "0"+to_string(h) : to_string(h)) + 
                ":" + 
                (m<10 ? "0"+to_string(m) : to_string(m)));
        }
    }
};
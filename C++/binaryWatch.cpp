class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for (int h=0; h<=11; h++){
            for (int m=0; m<=59; m++){
                if (numOnes(h, m)==num){
                    res.push_back(toTime(h, m));
                }
            }
        }
        return res;
    }
    
    int numOnes(int h, int m){
        int res = 0;
        while (h>0){
            res += (h%2);
            h/=2;
        }
        while (m>0){
            res += (m%2);
            m/=2;
        }
        return res;
    }
    
    string toTime(int h, int m){
        string hour = to_string(h);
        string minute = to_string(m);
        if (m<10){
            minute = "0"+minute;
        }
        return hour+":"+minute;
    }
};
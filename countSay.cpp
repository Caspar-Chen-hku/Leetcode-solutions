class Solution {
public:
    string countAndSay(int n) {
        if (n==1) return "1";
        string prev = countAndSay(n-1);
        string now = "";
        int count = 0;
        int current;
        int len = prev.length();
        for (int i=0; i<len; i++){
            count++;
            if (count==1) current = prev[i]-'0';
            if ((i<len-1&&prev[i]!=prev[i+1])||(i==len-1)){
                now += to_string(count);
                now += to_string(current);
                count = 0;
            }
        }
        return now;
    }
};
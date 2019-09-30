class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int> freq;
        for (char t:text){
            freq[t]++;
        }
        return min(freq['b'], min(freq['a'], min(freq['n'], min(freq['l']/2, freq['o']/2))));
    }
};
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> f(11, 0);
        for (string w:words){
            f[freq(w)]++;
        }
        vector<int> res;
        for (string q:queries){
            int sol = 0;
            int cur = freq(q);
            for (int i=cur+1; i<=10; i++){
                sol += f[i];
            }
            res.push_back(sol);
        }
        return res;
    }
    
    int freq(string w){
        sort(w.begin(), w.end());
        for (int i=0; i<w.length(); i++){
            if (i==w.length()-1 || w[i]!=w[i+1]){
                return i+1;
            }
        }
        return 0;
    }
};
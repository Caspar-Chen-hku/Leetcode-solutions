class Solution {
public:
    
    map<int, vector<int>> seq;
    
    vector<int> beautifulArray(int N) {
        if (seq.count(N)>0){
            return seq[N];
        }else if (N==1){
            return {1};
        }else{
            vector<int> res;
            for (int x:beautifulArray((N+1)/2)){
                res.push_back(2*x-1);
            }
            for (int x:beautifulArray(N/2)){
                res.push_back(2*x);
            }
            seq[N] = res;
            return res;
        }
    }
};
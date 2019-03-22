class Solution {
public:
    vector<int> grayCode(int n) {
        if (n==0){
            vector<int> result{0};
            return result;
        } 
        else if (n==1){
            vector<int> result{0,1};
            return result;
        }
        vector<int> rec = grayCode(n-1);
        int l=rec.size(), toAdd = pow(2,n-1);
        for (int i=l-1; i>=0; i--){
            rec.push_back(rec[i]+toAdd);
        }
        return rec;
    }
};
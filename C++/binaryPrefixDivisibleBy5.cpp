class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ans;
        int num = 0;
        for (int a:A){
            num = (2*num + a)%5;
            ans.push_back(num==0);
        }
        return ans;
    }
};
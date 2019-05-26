class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int n = A.size();
        vector<vector<int>> appear(n, vector<int>(26, 0));
        for (int i=0; i<n; i++){
            for (char c:A[i]){
                appear[i][c-'a']++;
            }
        }
        vector<string> res;
        bool exist;
        int minAppear;
        for (int j=0; j<26; j++){
            minAppear = 100;
            for (int i=0; i<n; i++){
                minAppear = min(minAppear, appear[i][j]);
                if (minAppear==0) break;
            }
            for (int i=0; i<minAppear; i++){
                res.push_back(string(1, 'a'+j));
            }
        }
        return res;
    }
};
class Solution {
public:
    
    vector<vector<int>> countPfx; 
    
    bool canPalindrome (string& str, int lo, int hi, int k) {
      int odd = 0; int count[26]={0};
      for (int j=0;j<26;j++) {
          count[j] = countPfx[hi][j];
          count[j] = lo>0? count[j] - countPfx[lo-1][j]: count[j];
      }
     for (int j = 0;j<26;j++) {
        if (count[j]&1) 
            ++odd; 
      }
      if ((hi-lo+1)&1) 
          --odd;
      return (k>=odd/2);   
   }
    
    vector<bool> canMakePaliQueries(string str, vector<vector<int>>& queries) {
        int N = str.length();
        vector<vector<int>> tmp (N+1,vector<int>(26,0)); 
        countPfx = tmp; 
        int sum[26] ={0};
        for (int j = 0;j<N;j++) {
          sum[str[j]-'a']++;
          for (int k = 0;k<26;k++) 
              countPfx[j][k] = sum[k];  
        }
        vector<bool> ans;
        for (auto q: queries) {
          bool x = canPalindrome(str,q[0],q[1],q[2]);
          ans.push_back(x);  
        }
        return ans; 
    }
};
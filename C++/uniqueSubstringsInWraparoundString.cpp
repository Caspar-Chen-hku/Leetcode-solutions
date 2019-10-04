class Solution {
public:
    int findSubstringInWraproundString(string p) {        
        int len = p.length();
        if(len == 0) return 0;
        if(len == 1) return 1;
        vector<int> res(26, 0);
        int count = 1;
        res[p[0]-'a'] = 1;
        for(int i = 1; i < len; i++){
            if(p[i] == p[i-1]+1 || (p[i] == 'a' && p[i-1] == 'z')){
                count++;
                res[p[i]-'a'] = max(res[p[i]-'a'], count);
            }
            else{
                res[p[i]-'a'] = max(res[p[i]-'a'], 1);
                count = 1;
            }
        }
        int cnt = 0;
        for(int num : res){
            cnt += num;
        }
        return cnt;
    }
};
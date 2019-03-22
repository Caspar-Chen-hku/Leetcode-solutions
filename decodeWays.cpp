class Solution {
public:
    
    int numDecodings(string s) {
        int l=s.length(), temp;
        if (l==0) return 0;
        int* nums = new int[l+1];
        nums[0] = 1;
        nums[1] = (s[0]=='0'?0:1);
        for (int i=2; i<=l; i++){
            nums[i]=0; temp = stoi(s.substr(i-2,2));
            if (s[i-1]!='0') nums[i]+=nums[i-1];
            if (s[i-2]!='0' && temp<=26) nums[i]+=nums[i-2];
        }
        return nums[l];
    }

};
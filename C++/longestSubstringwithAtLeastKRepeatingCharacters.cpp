class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.length()<k) return 0;
        return longest(s,k,0,s.length()-1);
    }
    
    int longest(string s, int k, int start, int end){
        if (end-start+1<k) return 0;
        int dict[26]{0};
        for (int i=start; i<=end; i++){
            dict[s[i]-'a']++;
        }
        for (int i=start; i<=end; i++){
            if (dict[s[i]-'a']>0 && dict[s[i]-'a']<k){
                return max(longest(s,k,start,i-1),longest(s,k,i+1,end));
            }
        }
        return (end-start+1);
    }
};
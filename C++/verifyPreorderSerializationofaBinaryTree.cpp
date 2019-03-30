class Solution {
public:
    bool isValidSerialization(string preorder) {
        int count = 0;
        if (preorder.back()!='#') return false;
        for (int i=1; i<preorder.length()-1; i++){
            if (preorder[i]==','){
                if (preorder[i-1]=='#'){
                    count--;
                }else{
                    count++;
                }
            }
            if (count<0) return false;
        }
        return (count==0);
    }
};
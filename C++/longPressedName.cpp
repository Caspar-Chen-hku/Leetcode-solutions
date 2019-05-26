class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0, j=0, l1=name.length(), l2=typed.length(), count1, count2;
        while (i<l1 && j<l2){
            if (name[i]!=typed[j]) return false;
            count1 = count2 = 1;
            while (i+1<l1 && name[i+1]==name[i]) {i++; count1++;}
            while (j+1<l2 && typed[j+1]==typed[j]) {j++; count2++;}
            if (count1>count2) return false;
            i++; j++;
        }
        return (i==l1 && j==l2);
    }
};
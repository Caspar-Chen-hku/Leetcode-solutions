class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        sort(letters.begin(), letters.end());
        if (target>=letters.back()) return letters[0];
        int i = 0, j = letters.size()-1, mid;
        while (i<=j){
            mid = (i+j)/2;
            if (letters[mid]>target && (mid==0 || letters[mid-1]<=target)) 
                return letters[mid];
            else if (letters[mid]<=target) i=mid+1;
            else j=mid-1;
        }
        return letters.back();
    }
};
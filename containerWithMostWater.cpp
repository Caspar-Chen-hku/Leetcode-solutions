class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = height.size();
        int i=0;
        int j=l-1;
        int area = 0;
        int temp;
        while (i<j){
            if (height[i]<height[j]){
                temp = (j-i)*height[i];
                i++;
            }else{
                temp = (j-i)*height[j];
                j--;
            }
            if (temp>area){
                area=temp;
            }
        }
        return area;
    }
    
};
class Solution {
public:
    
    void fill(vector<int>& height, int i, int j, int toadd){
        for (int index=i; index<=j; index++){
            height[index]=toadd;
        }
    }
    
    int trap(vector<int>& height) {
        int n = height.size();
        if (n<3) return 0; 
        
        int result = 0;
        int temp = 0;
        int toadd = 0;
        int prev=-1;
        
        for (int i=0; i<n; i++){
            if (height[i]>=toadd) {
                result += temp;
                cout << result << ":" << i << endl;
                temp = 0;
                if (prev!=-1){
                    fill(height, prev, i-1, toadd);
                }
                toadd = height[i];
                prev = i;
            }
            else if (height[i]<toadd){
                temp += (toadd - height[i]);
            }
        }
        temp = 0;
        toadd = 0;
        prev = -1;
        for (int i=n-1; i>=0; i--){
            if (height[i]>=toadd) {
                result += temp;
                cout << result << ":" << i << endl;
                temp = 0;
                toadd = height[i];
                if (prev!=-1){
                    fill(height, prev, i-1, toadd);
                }
                toadd = height[i];
                prev = i;
            }
            else if (height[i]<toadd){
                temp += (toadd - height[i]);
            }
        }
        return result;
    }
};
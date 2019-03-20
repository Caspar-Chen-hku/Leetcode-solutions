class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(), largest=0;
        if (n==0) return 0;
        heights.push_back(0); n++;
        stack<int> ind;
        int i=0, temp, t, result = 0;
        while (i<n){
            if (ind.empty() || heights[ind.top()] <= heights[i]){
                ind.push(i);
                i++;
            }else{
                t = ind.top();
                ind.pop();
                temp= heights[t] * (ind.empty() ? i : i - ind.top() - 1);
                if (temp>result) result=temp;
            }
        }
        return result;        
    }
    
};
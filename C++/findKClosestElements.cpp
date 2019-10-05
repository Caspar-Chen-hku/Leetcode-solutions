class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int ind = find(arr, x);
        int i = ind, j = ind+1;
        vector<int> res;
        while (k>0){
            if (i<0){
                j++;
            }else if (j>=arr.size()){
                i--;
            }else if (x-arr[i] <= arr[j]-x){
                i--;
            }else{
                j++;
            }
            k--;
        }
        for (int ind=i+1; ind<j; ind++){
            res.push_back(arr[ind]);
        }
        return res;
    }
    
    int find(vector<int> arr, int x){
        int i=0, j=arr.size()-1, mid;
        while (i<=j){
            mid = (i+j)/2;
            if (mid==arr.size()-1 || (arr[mid]<=x && arr[mid+1]>=x)){
                return mid;
            }else if (arr[mid]>x){
                j = mid-1;
            }else{
                i = mid+1;
            }
        }
        return -1;
    }
};
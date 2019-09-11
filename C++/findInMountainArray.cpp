/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    
    vector<int> arr;
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        arr = vector<int>(mountainArr.length(), -1);
        int pivot = findPivot(mountainArr);
        int prior = searchPrior(target, pivot, mountainArr);
        if (prior==-1){
            return searchLatter(target, pivot, mountainArr);
        }else{
            return prior;
        }
    }
    
    int getele(MountainArray &mountainArr, int index){
        if (arr[index]==-1){
            arr[index] = mountainArr.get(index);
        }
        return arr[index];
    }
    
    int findPivot(MountainArray &m){
        int i=0, j=m.length()-1, mid;
        while (i<=j){
            mid = (i+j)/2;
            if (mid==0){
                i = 1;
            }else if (mid==m.length()-1){
                j = mid-1;
            }else if (getele(m, mid) > getele(m, mid-1) && getele(m, mid) > getele(m, mid+1)){
                return mid;
            }else if (getele(m, mid) < getele(m, mid-1)){
                j = mid-1;
            }else{
                i = mid +1;
            }
        }
        return -1;
    }
    
    int searchPrior(int target, int pivot, MountainArray &m){
        int i=0, j=pivot, mid;
        while (i<=j){
            mid = (i+j)/2;
            if (getele(m, mid)== target){
                return mid;
            }else if (getele(m, mid) > target){
                j = mid-1;
            }else{
                i = mid +1;
            }
        }
        return -1;
    }
    
    int searchLatter(int target, int pivot, MountainArray &m){
        int i=pivot+1, j=m.length()-1, mid;
        while (i<=j){
            mid = (i+j)/2;
            if (getele(m, mid)== target){
                return mid;
            }else if (getele(m, mid) < target){
                j = mid-1;
            }else{
                i = mid +1;
            }
        }
        return -1;
    }    
};
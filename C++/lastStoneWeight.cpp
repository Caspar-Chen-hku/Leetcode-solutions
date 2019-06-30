class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        return lastweight(stones);
    }
    
    int lastweight(vector<int>& stones){
        if (stones.size()==0){
            return 0;
        }else if (stones.size()==1){
            return stones[0];
        }else{
            int y = stones.back();
            stones.pop_back();
            int x = stones.back();
            stones.pop_back();
            if (y>x){
                stones.insert(stones.begin()+ind(stones,y-x), y-x);
            }
            return lastweight(stones);
        }
    }
    
    int ind(vector<int>& stones, int target){
        int i = 0, j = stones.size()-1, mid;
        while (i<=j){
            mid = (i+j)/2;
            if (stones[mid]>=target && (mid==0 || stones[mid-1]<=target)){
                return mid;
            }else if (stones[mid]<target){
                i = mid+1;
            }else{
                j = mid-1;
            }
        }
        return stones.size();
    }
};
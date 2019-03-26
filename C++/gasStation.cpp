class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (int i=0; i<gas.size(); i++){
            if (can(gas,cost,i,i,0)!=-1) return i;
        }
        return -1;
    }
    
    int can(vector<int>& gas, vector<int>& cost, int start, int curind, int curgas){
        int l = gas.size();
        if (curind==start+l){
            return start;
        }
        else if (curgas+gas[curind%l]<cost[curind%l]){
            return -1;
        }
        
        int result = can(gas,cost,start,curind+1,curgas+gas[curind%l]-cost[curind%l]);
        return result;
    }
};
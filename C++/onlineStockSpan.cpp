class StockSpanner {
public:
    
    //this records the next info
    vector<int> v;
    //this records the prices
    vector<int> p;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        if (v.empty()){
            v.push_back(1);
            p.push_back(price);
            return 1;
        }else{
            if (p.back()>price){
                v.push_back(1);
                p.push_back(price);
                return 1;
            }else{
                int curInd = p.size()-1;
                int nextInd;
                while (p[curInd]<=price){
                    nextInd = curInd - v[curInd] + 1;
                    if (nextInd==curInd) break;
                    curInd = nextInd;
                }
                while (curInd>0 && p[curInd-1]<=price){
                    curInd--;
                }
                v.push_back(p.size()-curInd);
                p.push_back(price);
                return p.size()-curInd;
            }
        }    
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
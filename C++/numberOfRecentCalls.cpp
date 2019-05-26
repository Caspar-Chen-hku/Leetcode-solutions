class RecentCounter {
public:
    
    vector<int> pings;
    int start = 0;
    
    RecentCounter() {
        
    }
    
    int ping(int t) {
        pings.push_back(t);
        int i=start, j=pings.size()-1, mid;
        while (i<=j){
            mid = (i+j)/2;
            if (pings[mid]>=t-3000 && (mid==0 || pings[mid-1]<t-3000)){
                start = mid;
                return (pings.size()-mid);   
            }
            else if (pings[mid]<t-3000) i=mid+1;
            else j=mid-1;
        }
        return 0;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
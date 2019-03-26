class LRUCache {
public:
    
    map<int,int> cache;
    map<int,int> time;
    int cap;
    int clock = 0;
    
    LRUCache(int capacity) {
        cap = capacity;   
    }
    
    int get(int key) {
        if (cache.count(key)>0){
            time[key]=clock;
            clock++;
            return cache[key];
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (cache.count(key)>0 || cache.size()<cap){
            cache[key] = value;
        }else{
            int minim = INT_MAX, ind;
            for (auto it=time.begin(); it!=time.end(); it++){
                if (it->second<minim){
                    minim=it->second;
                    ind = it->first;
                }
            }
            cache.erase(ind);
            time.erase(ind);
            cache[key] = value;
        }
        time[key]=clock;
        clock++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
class MapSum {
public:
    /** Initialize your data structure here. */

    map<string, int> keys;
    map<string, int> prefices;
    
    MapSum() {
        keys.clear();
        prefices.clear();
    }
    
    void insert(string key, int val) {
        int delta = (keys.count(key)==0 ? val : val-keys[key]);
        keys[key] = val;
        for (int i=1; i<=key.length(); i++){
            prefices[key.substr(0,i)] += delta;
        }
    }
    
    int sum(string prefix) {
        return prefices[prefix];
    }
};



/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
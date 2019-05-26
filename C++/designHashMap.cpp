class MyHashMap {
public:
    /** Initialize your data structure here. */
    
    vector<int> keys;
    vector<int> vals;
    
    MyHashMap() {
        keys.clear();
        vals.clear();
    }
    
    
    int findKey(int key){
        for (int i=0; i<keys.size(); i++){
            if (keys[i]==key){
                return i;
            }
        }
        return -1;
    }
    /** value will always be non-negative. */
    void put(int key, int value) {
        int temp = findKey(key);
        if (temp!=-1){
            keys[temp] = key;
            vals[temp] = value;
        }else{
            keys.push_back(key);
            vals.push_back(value);
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        for (int i=0; i<keys.size(); i++){
            if (keys[i]==key){
                return vals[i];
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int temp = findKey(key);
        if (temp!=-1){
            keys.erase(keys.begin()+temp);
            vals.erase(vals.begin()+temp);
            return;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
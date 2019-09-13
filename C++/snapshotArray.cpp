class SnapshotArray {
public:
    
    int cur = 0;
    map<pair<int,int>, int> m;
    SnapshotArray(int length) {
        
    }
    
    void set(int index, int val) {
        m[{cur,index}] = val;
    }
    
    int snap() {
        return cur++;
    }
    
    int get(int index, int snap_id) {
        while (m.count({snap_id,index})==0 && snap_id>=0){
            snap_id--;
        }
        return m[{snap_id,index}];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
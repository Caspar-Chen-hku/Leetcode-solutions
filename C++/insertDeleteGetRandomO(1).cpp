class RandomizedSet {
public:
    
    set<int> myset;
    
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        return (myset.insert(val).second);
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        return (myset.erase(val)==1);
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int num = (int) (rand() % myset.size());
        set<int>::const_iterator it(myset.begin());
        advance(it,num);
        return (*it);
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
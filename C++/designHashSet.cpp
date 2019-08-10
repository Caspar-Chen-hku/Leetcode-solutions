class MyHashSet {
  std::bitset<10'000'000> tbl;
    
  public:
  MyHashSet() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
  }

  void add(int key) noexcept {
    tbl.set(key);
  }

  void remove(int key) noexcept {
    tbl.reset(key);
  }

  /** Returns true if this set contains the specified element */
  bool contains(int key) const noexcept {
    return tbl.test(key);
  }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
class MyCircularDeque {
private:
    vector<int> dq;
    int sz;
    
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        sz = k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (dq.size() == sz) return false;
        
        dq.insert(dq.begin(), value);
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (dq.size() == sz) return false;
        
        dq.push_back(value);
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (dq.empty()) return false;
        
        dq.erase(dq.begin());        
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (dq.empty()) return false;
        
        dq.erase(dq.begin() + dq.size() - 1);        
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (dq.empty()) return -1;
        
        return dq[0];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (dq.empty()) return -1;
        
        return dq.back();
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        if (dq.empty()) return true;
        
        return false;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        if (dq.size() == sz) return true;
        
        return false;
    }
};
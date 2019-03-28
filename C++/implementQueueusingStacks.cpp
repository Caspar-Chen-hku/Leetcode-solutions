class MyQueue {
public:
    stack<int> mains;
    stack<int> fronts;
    
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        mains.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int temp = peek();
        fronts.pop();
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        if (!fronts.empty()){
            return fronts.top();
        }else{
            int temp = mains.size()-1;
            for (int i=0; i<temp; i++){
                fronts.push(mains.top());
                mains.pop();
            }
            int front = mains.top();
            mains.pop();
            for (int i=0; i<temp; i++){
                mains.push(fronts.top());
                fronts.pop();
            }
            fronts.push(front);
            return front;
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return mains.empty() && fronts.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
class MyStack {
public:
    
    queue<int> topq;
    queue<int> mainq;
    
    /** Initialize your data structure here. */
    MyStack() {
            
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if (!topq.empty()){
            mainq.push(topq.front());
            topq.pop();
        }
        topq.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = top();
        topq.pop();
        return res;
    }
    
    /** Get the top element. */
    int top() {
        if (!topq.empty()){
            return topq.front();
        }else{
            for (int i=0; i<mainq.size()-1; i++){
                mainq.push(mainq.front()); mainq.pop();
            }
            topq.push(mainq.front());
            mainq.pop();
            return topq.front();
        }
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return mainq.empty() && topq.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
class MinStack {
public:
    /** initialize your data structure here. */
    
    stack<int> mainstack;
    stack<int> minstack;
    
    MinStack() {
        
    }
    
    void push(int x) {
        mainstack.push(x);
        if (minstack.empty() || minstack.top()>x){
            minstack.push(x);
        }else{
            minstack.push(minstack.top());
        }
    }
    
    void pop() {
        mainstack.pop();
        minstack.pop();
    }
    
    int top() {
        return mainstack.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */